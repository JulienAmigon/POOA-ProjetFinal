#include "fenetre.h"

FenetreGraph::FenetreGraph(QWidget* parent) : QWidget{parent}
{
    // Initialisation de la fenêtre
    float w = 1280;
    float h = 720;
    setFixedSize(w, h);

    // La fenêtre contient une scène QGraphicsScene principale, avec sa vue.
    // Les autres scènes, qui seront plus exactement des classes Scene sont dans cette vue
    scene = new QGraphicsScene(0, 0, w, h);

    view = new QGraphicsView(scene, this);
    view->setAlignment(Qt::AlignCenter);

    areaCursor = new SceneCursor(0, 0, w, 0.2*h, view);
    areaPixels = new ScenePixels(0.3*w, 0.2*h, 0.7*w, 0.8*h, view);
    areaShapes = new SceneShapes(0, 0.2*h, 0.3*w, 0.8*h, view);


    // Initalisation du Pointeur
    // Taille de base à 7 et de couleur rouge
    pointer = new Pointer();
    pointer->SetColor(QColor(255, 0, 0));
    pointer->SetSize(7);
    pointer->SetDrawMethod(nullptr);


    // Initalisation manuelle des boutons de modification du pointeur
    areaCursor->addColorButton("Blue", Qt::blue, pointer, this);
    areaCursor->addColorButton("Red", Qt::red, pointer, this);
    areaCursor->addColorButton("Yellow", Qt::yellow, pointer, this);

    Pointer * p = pointer;

    buttonPlus = new QPushButton("+", this);
    buttonPlus->setGeometry(QRect(QPoint(210, 0), QSize(50, 50)));
    connect(buttonPlus, &QPushButton::clicked, this, [p]() { p->SetSize(p->GetSize() + 1); });

    buttonMinus = new QPushButton("-", this);
    buttonMinus->setGeometry(QRect(QPoint(280, 0), QSize(50, 50)));
    connect(buttonMinus, &QPushButton::clicked, this, [p]() { p->SetSize(p->GetSize() - 1); });


    // Chargement des plugins
    LoadDlls();
}


FenetreGraph::~FenetreGraph()
{
    delete buttonPlus;
    delete buttonMinus;
    delete pointer;
    delete areaCursor;
    delete areaPixels;
    delete areaShapes;
    scene->clear();
    delete scene;
    delete view;
}


/****************************************************************/
/* Méthode qui charge les fonctions de dll du dossier "Plugins" */
/****************************************************************/
void FenetreGraph::LoadDlls()
{
    // Liste de chaque fichier .dll
    QDir pluginsDir(getPath());
    QStringList listDlls = pluginsDir.entryList(QStringList("*.dll"));

    // Pour chacun, on va récupérer la méthode de dessin, si elle existe
    for (qsizetype i = 0; i < listDlls.size(); ++i) {
        QString nameDll = listDlls.value(i);
        QLibrary library(getPath()+'/'+nameDll);

        if(!library.load())  {
            qDebug() << "Error : could not load " << nameDll;
            continue;
        }
        else
            qDebug() << nameDll << " successfully loaded";

        GetPixels functionDraw = (GetPixels)library.resolve("draw");

        if (functionDraw == nullptr) {
            library.unload();
            continue;
        }


        // Puis on va indiquer à la zone des plugins d'ajouter le boutons associé
        std::string name = nameDll.toStdString().substr(0, nameDll.length() - 4);
        getAreaShape()->addDrawMethod(name, functionDraw);
        getAreaShape()->createNewButton(name, functionDraw, pointer, this);
    }
}


/*********************************************************************/
/* Méthode pour récupérer le clic de la souris et effectuer l'action */
/*********************************************************************/
void FenetreGraph::mousePressEvent(QMouseEvent* event)
{
    QPoint point = event->pos();

    if (areaPixels->isCursorInScene(point))
    {
        areaPixels->onClick(point, pointer);
    }
}

