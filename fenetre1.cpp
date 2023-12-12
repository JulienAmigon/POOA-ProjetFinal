#include "fenetre1.h"
#include "Scenes/SceneCursor.h"
#include "Scenes/ScenePixels.h"
#include "Scenes/SceneShapes.h"

FenetreGraph::FenetreGraph(QWidget* parent) : QWidget{parent}
{
    float w = 1280;
    float h = 720;
    setFixedSize(w, h);

    scene = new QGraphicsScene(0, 0, w, h);
    view = new QGraphicsView(scene, this);

    view->setAlignment(Qt::AlignCenter);


    scenes.push_back(new SceneCursor(0, 0, w, 0.2*h, view));
    scenes.push_back(new ScenePixels(0.3*w, 0.2*h, 0.7*w, 0.8*h, view));
    scenes.push_back(new SceneShapes(0, 0.2*h, 0.3*w, 0.8*h, view));


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

    triangle = new QPushButton("triangele", this);
    triangle->setGeometry(QRect(QPoint(210, 0), QSize(50, 50)));
    connect(triangle, &QPushButton::clicked, this, &FenetreGraph::changeTriangle);
}


FenetreGraph::~FenetreGraph()
{
    for (auto s : scenes)
    {
        delete s;
    }
    delete scene;
    delete view;
    delete pointer;
    delete buttonBlue;
    for (int i = 0; i < buttonListPerso.size(); ++i) {
        delete buttonListPerso.at(i);
    }
}

void FenetreGraph::changeTriangle() {

    pointer->SetDrawMethod([] (QPoint point, int size) -> std::vector<QPoint> {
        std::vector<QPoint> pixels;

        for (int i = -size + 1; i < size; i++)
        {
            for (int j = -size + 1; j < size; j++)
            {
                if( i != j)
                    pixels.push_back(point + QPoint(i, j));
            }
        }

        return pixels;
    });

}


// Liste les formes persos et crée les boutons associés
void FenetreGraph::loadFormesPerso() {
    QString path = QDir().currentPath()+"/FormesPerso";
    QDir dir(path);
    //qDebug() << "Liste des formes persos : " << path;

    // Liste des fichiers du dossier
    QStringList fileList = dir.entryList(QDir::Files);

    // Pour chaque fichier, on l'ajoute en tant que bouton
    for (qsizetype i = 0; i < fileList.size(); ++i) {
        QString fileName = fileList.value(i);
        qDebug() << fileName;

        QPushButton * btn = new QPushButton(fileName, this);
        btn->setGeometry(QRect(QPoint(250, 30*buttonListPerso.size()), QSize(100, 20)));
        connect(btn, &QPushButton::clicked, this, [this, fileName]() {
           FormesPerso(fileName);
        });

        buttonListPerso.append(btn);
    }
    qDebug() << "";
}

void FenetreGraph::FormesPerso(QString fileName) {
    qDebug() << "Forme perso : " << fileName;
}


void FenetreGraph::mousePressEvent(QMouseEvent* event)
{
    QPoint point = event->pos();

    for (auto s : scenes)
    {
        if (s->isCursorInScene(point))
        {
            s->onClick(point, pointer);
        }
    }
}
