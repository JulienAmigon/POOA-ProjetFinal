#include "fenetre.h"

QString str("D:/QtProjects/build-Zone-Desktop_Qt_6_6_0_MinGW_64_bit-Debug/FormesPerso/tricyrcle");

Fenetre::Fenetre(QWidget *parent)
    : QWidget{parent}
{
    p = new Pointeur();
    e = new Eraser();
    //custom = new CustomForm();

    s = new Square();
    c = new Circle();
    t = new Triangle();

    m = p;

    setFixedSize(1000, 700);
    scene = new QGraphicsScene(0, 0, 1000, 400);
    view = new QGraphicsView(this);
    view->setScene(scene);

    changeColor(Qt::red);



    buttonPointeur = new QPushButton("Pointage", this);
    buttonPointeur->setGeometry(QRect(QPoint(0, 0), QSize(100, 20)));
    connect(buttonPointeur, &QPushButton::clicked, this, &Fenetre::switchPointeurMode);

    buttonSquare = new QPushButton("Carré", this);
    buttonSquare->setGeometry(QRect(QPoint(0, 60), QSize(100, 20)));
    connect(buttonSquare, &QPushButton::clicked, this, &Fenetre::switchSquareMode);

    buttonCircle = new QPushButton("Cercle", this);
    buttonCircle->setGeometry(QRect(QPoint(0, 30), QSize(100, 20)));
    connect(buttonCircle, &QPushButton::clicked, this, &Fenetre::switchCircleMode);

    buttonTriangle = new QPushButton("Triangle", this);
    buttonTriangle->setGeometry(QRect(QPoint(0, 90), QSize(100, 20)));
    connect(buttonTriangle, &QPushButton::clicked, this, &Fenetre::switchTriangleMode);

    buttonEraser = new QPushButton("Eraser", this);
    buttonEraser->setGeometry(QRect(QPoint(0, 120), QSize(100, 20)));
    connect(buttonEraser, &QPushButton::clicked, this, &Fenetre::switchEraserMode);


    QColor rouge = Qt::red;
    buttonRed = new QPushButton("Red", this);
    buttonRed->setGeometry(QRect(QPoint(0, 150), QSize(100, 20)));
    //connect(buttonRed, &QPushButton::clicked, this, &Fenetre::changeColor());
    connect(buttonRed, &QPushButton::clicked, this, [this, rouge]() {
        changeColor(rouge);
    });


    QColor bleu = Qt::blue;
    buttonBlue = new QPushButton("Blue", this);
    buttonBlue->setGeometry(QRect(QPoint(0, 180), QSize(100, 20)));
    //connect(buttonBlue, &QPushButton::clicked, this, &Fenetre::changeColor(Qt::blue));
    connect(buttonBlue, &QPushButton::clicked, this, [this, bleu]() {
        changeColor(bleu);
    });

    QColor jaune = Qt::yellow;
    buttonYellow = new QPushButton("Yellow", this);
    buttonYellow->setGeometry(QRect(QPoint(0, 210), QSize(100, 20)));
    //connect(buttonYellow, &QPushButton::clicked, this, &Fenetre::changeColor(Qt::yellow));
    connect(buttonYellow, &QPushButton::clicked, this, [this, jaune]() {
        changeColor(jaune);
    });



    buttonSave = new QPushButton("Save", this);
    buttonSave->setGeometry(QRect(QPoint(125, 0), QSize(100, 20)));
    connect(buttonSave, &QPushButton::clicked, this, &Fenetre::saveForm);

    buttonLoad = new QPushButton("Load", this);
    buttonLoad->setGeometry(QRect(QPoint(125, 30), QSize(100, 20)));
    connect(buttonLoad, &QPushButton::clicked, this, &Fenetre::loadForm);

    listFormesPerso();
}


// Lit le fichier passé en "path"
void Fenetre::lecture(QString path) {
    qDebug() << "\nLecture de :" << path;
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "Fenetre::lecture : " << path << "non ouvert";
    else
    {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            qDebug() << line;
        }
        qDebug() << "";
    }
}


// Sauvegade la fenêtre actuelle dans un fichier
void Fenetre::saveForm() {
    // Accès au dossier "FormesPerso"
    QString path = QDir().currentPath()+"/FormesPerso";

    // Demande à ajouter un truc
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save File"),
                                                    path,
                                                    tr("All Files (*)"));

    // Ajoute un fichier
    if(!fileName.isEmpty()) {

        // Accès à toutes les formes de la fenêtre
        QList<QGraphicsItem *> list;
        list = getScene()->items();

        // Création du fichier
        createFile(fileName, list);
    }
    else
        qDebug() << "Fenetre::saveForm : Le nom du fichier est vide" << fileName;
}


// Création d'un fichier 'pathfile' et le remplis de la 'list'  // A séparer en deux fonctions
void Fenetre::createFile(QString pathFile, QList<QGraphicsItem *> list) {
    QFile file(pathFile);
    if (file.open(QIODevice::ReadWrite)) {

        // Pour écrire le contenu dans le fichier
        QTextStream stream(&file);

        for (qsizetype i = 0; i < list.size(); ++i) {
            // type de la forme (5 = triangle (polygon), 4 = rond (ellipse), 3 = carré (rect)). Peut passer par QGraphicsRectItem::Type aussi
            stream << list.value(i)->type();

            // La couleur est stockée dans la sous-classe de GaphicsItem, AbsractShape, on va donc se caster en lui
            QAbstractGraphicsShapeItem *shapeItem = qgraphicsitem_cast<QAbstractGraphicsShapeItem *>(list.value(i));
            QColor br = shapeItem->brush().color();

            stream << " " << br.red() << " " << br.blue() << " " << br.green();

            // Les positions
            stream << " " << list.value(i)->boundingRect().topLeft().x() << " " << list.value(i)->boundingRect().topLeft().y();

            stream << '\n';
        }
    }
    else
        qDebug() << "Fenetre::createFile : Impossible d'accéder au fichier :" << pathFile;


    //lecture(pathFile);
    file.close();
}


// Charge un fichier (ici, l'affiche, surtout)
void Fenetre::loadForm() {
    // Accès au dossier "FormesPerso"
    QString path = QDir().currentPath()+"/FormesPerso";

    // Demande à ajouter un truc
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    path,
                                                    tr("All Files (*)"));

    // Ajoute un fichier
    if(!fileName.isEmpty()) {

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
            qDebug() << "Fenetre::loadForm : " << path << "non ouvert";
        else
        {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                qDebug() << line;
            }
            qDebug() << "";
        }
        file.close();
    }
    else
        qDebug() << "Fenetre::loadForm : Le nom du fichier est vide" << fileName;

}


// Liste les formes persos et crée les boutons associés
void Fenetre::listFormesPerso() {
    QString path = QDir().currentPath()+"/FormesPerso";
    QDir dir(path);
    qDebug() << "Liste des formes persos : " << path;

    // Liste des fichiers du dossier
    QStringList fileList = dir.entryList(QDir::Files);

    // Pour chaque fichier, on l'ajoute en tant que bouton
    for (qsizetype i = 0; i < fileList.size(); ++i) {
        QString fileName = fileList.value(i);
        qDebug() << fileName;

        QPushButton * btn = new QPushButton(fileName, this);
        //btn->setGeometry(QRect(QPoint(250, 30*buttonList.size()), QSize(100, 20)));
        //btn->move(QPoint(250, 30*buttonList.size()));
        //connect(btn, &QPushButton::clicked, this, &Fenetre::switchModePerso);
        connect(btn, &QPushButton::clicked, this, [this, fileName]() {
            switchModePerso(fileName);
        });

        buttonList.append(btn);
        //buttonList.append(new QPushButton(fileName, this));
    }
    qDebug() << "";

}



/************************************************************************************************/
/* Fonction qui permet de gérer le clic de la souris sur l'écran pour créer de la nourriture    */
/************************************************************************************************/
void Fenetre::mousePressEvent(QMouseEvent *event)
{
    // On stocke la position du curseur dans un point
    QPoint point;
    point.setX(event->pos().x());
    point.setY(event->pos().y());

    // Au clic gauche, on émet le signal "onClick" qui avec ce point
    //if ( event->button() == Qt::LeftButton ) emit onClick(point);

    cout << "Click (" <<  point.x() << ";"  << point.y() << ")" << endl;

    //Affichage(m->dessiner(point, couleur));

    if(m->getMode() == e->getMode()) {
        if (QGraphicsItem *item = getView()->itemAt(event->pos())) {
            getScene()->removeItem(item);
        } else {
            qDebug("Mode Erase : no item");
        }
    }
    else {
        Affichage(m->action(point, couleur));
    }
}


/*******************************************/
/* Ajoute un objet graphique à la scène    */
/*******************************************/
void Fenetre::Affichage(QGraphicsItem *sprite)
{
    if(sprite != nullptr) {
        try {
            getScene()->addItem(sprite);
        }
        catch(...) {
            std::cout << "Erreur lors de l'affichage d'un element" << std::endl;
            exit(-1);
        }
    }
}
