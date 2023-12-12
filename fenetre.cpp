#include "fenetre.h"


FenetreGraph::FenetreGraph(QWidget* parent) : QWidget{parent}
{
    float w = 1280;
    float h = 720;
    setFixedSize(w, h);

    scene = new QGraphicsScene(0, 0, w, h);
    view = new QGraphicsView(scene, this);

    view->setAlignment(Qt::AlignCenter);


    areaCursor = new SceneCursor(0, 0, w, 0.2*h, view);
    areaPixels = new ScenePixels(0.3*w, 0.2*h, 0.7*w, 0.8*h, view);
    areaShapes = new SceneShapes(0, 0.2*h, 0.3*w, 0.8*h, view);



    pointer = new Pointer();
    pointer->SetColor(QColor(255, 0, 0));
    pointer->SetSize(3);
    pointer->SetDrawMethod([] (QPoint point, int size) -> std::vector<QPoint> {
        std::vector<QPoint> pixels;

        for (int i = -size + 1; i < size; i++)
        {
            for (int j = -size + 1; j < size; j++)
            {
                pixels.push_back(point + QPoint(i, j));
            }
        }

        return pixels;
    });


    buttonBlue = new QPushButton("Blue", this);
    buttonBlue->setGeometry(QRect(QPoint(0, 0), QSize(50, 50)));
    connect(buttonBlue, &QPushButton::clicked, this, &FenetreGraph::changeColorBlue);

    buttonRed = new QPushButton("Red", this);
    buttonRed->setGeometry(QRect(QPoint(70, 0), QSize(50, 50)));
    connect(buttonRed, &QPushButton::clicked, this, &FenetreGraph::changeColorRed);

    buttonYellow = new QPushButton("Yellow", this);
    buttonYellow->setGeometry(QRect(QPoint(140, 0), QSize(50, 50)));
    connect(buttonYellow, &QPushButton::clicked, this, &FenetreGraph::changeColorYellow);

    Pointer * p = pointer;

    buttonPlus = new QPushButton("+", this);
    buttonPlus->setGeometry(QRect(QPoint(210, 0), QSize(50, 50)));
    connect(buttonPlus, &QPushButton::clicked, this, [p]() { p->SetSize(p->GetSize() + 1); });

    buttonMinus = new QPushButton("-", this);
    buttonMinus->setGeometry(QRect(QPoint(280, 0), QSize(50, 50)));
    connect(buttonMinus, &QPushButton::clicked, this, [p]() { p->SetSize(p->GetSize() - 1); });

    //loadFormesPerso();
    LoadDlls();
}


FenetreGraph::~FenetreGraph()
{
    delete areaCursor;
    delete areaPixels;
    delete areaShapes;
  
    scene->clear();
    delete scene;
    delete view;
    delete pointer;
    delete buttonBlue;
    delete buttonYellow;
    delete buttonRed;
    for (int i = 0; i < buttonListPerso.size(); ++i) {
        delete buttonListPerso.at(i);
    }
}





void FenetreGraph::LoadDlls()
{
    QDir pluginsDir(getPath());

    QStringList listDlls = pluginsDir.entryList(QStringList("*.dll"));

    for (qsizetype i = 0; i < listDlls.size(); ++i)
    {
        QString nameDll = listDlls.value(i);
        QLibrary dll(getPath()+'/'+nameDll);

        if(!dll.load())
        {
            qDebug() << "Error : could not load " << nameDll;
            continue;
        }

        qDebug() << nameDll << " successfully loaded";

        GetPixels fct = (GetPixels)dll.resolve("draw");

        if (fct == nullptr)
        {
            dll.unload();
            continue;
        }

        std::string name = nameDll.toStdString().substr(0, nameDll.length() - 4);
        areaShapes->addDrawMethod(name, fct);
        areaShapes->createNewButton(name, fct, pointer, this);
        //createNewButton(std::string name, GetPixels fct, Pointer* pointer, QWidget* parent)
    }
}



/*
// Récupère les formes persos et crée les boutons associés
void FenetreGraph::loadFormesPerso() {
    QDir dir(getPath());

    // Liste des fichiers .dll du dossier
    QStringList fileList = dir.entryList(QStringList("*.dll"));
    QString fileName;

    // Pour chaque fichier, on l'ajoute en tant que bouton
    for (qsizetype i = 0; i < fileList.size(); ++i) {


        fileName = fileList.value(i);
        qDebug() << fileName;

        QPushButton * btn = new QPushButton(fileName, this);
        connect(btn, &QPushButton::clicked, this, [this, fileName]() {
           loadForme(fileName);
        });

        // On centre les boutons sur x = 300, y selon la place dans la liste
        btn->adjustSize();
        btn->move(QPoint(300-(btn->width()/2), 30*buttonListPerso.size()));

        // Ajout à la liste. Pour l'instant uniquement pour les supprimer dans le destructeur
        buttonListPerso.append(btn);
    }
    qDebug() << "End of directory";
}


// Charge la forme associée à fileName dans le pointeur
void FenetreGraph::loadForme(QString fileName) {

    // On ouvre le .dll
    QLibrary library(getPath()+'/'+fileName);
    if (!library.load())
        qDebug() << library.errorString();
    if (library.load())
        qDebug() << "library loaded";

    // On crée la fonction
    typedef std::vector<QPoint> (*DrawMethod)(QPoint, int);
    DrawMethod draw = (DrawMethod)library.resolve("draw");

    // Puis on l'applique sur le pointer
    if (draw) {
        pointer->SetDrawMethod(draw);
        qDebug() << fileName << " loaded";
    } else {
        qDebug() << fileName << " not loaded";
    }

    // problème si on clique plusieurs fois ca load à chaque fois. Avoir library en attribut et on appelle toujours unload puis load ?
}
*/



void FenetreGraph::mousePressEvent(QMouseEvent* event)
{
    QPoint point = event->pos();

    if (areaPixels->isCursorInScene(point))
    {
        areaPixels->onClick(point, pointer);
    }
}

