#include "fenetre1.h"
#include "Scenes/SceneCursor.h"
#include "Scenes/ScenePixels.h"
#include "Scenes/SceneShapes.h"
#include "qdir.h"
#include "qevent.h"
#include "qgraphicsview.h"
#include <iostream>

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
}


FenetreGraph::~FenetreGraph()
{
    delete areaCursor;
    delete areaPixels;
    delete areaShapes;
}


void FenetreGraph::mousePressEvent(QMouseEvent* event)
{
    QPoint point = event->pos();

    if (areaPixels->isCursorInScene(point))
    {
        areaPixels->onClick(point, pointer);
    }
}



void FenetreGraph::LoadDlls()
{
    QDir pluginsDir(QDir().currentPath() + "/Plugins");

    QStringList listDlls = pluginsDir.entryList(QStringList("*.dll"));

    for (const auto &nameDll : listDlls)
    {
        QLibrary dll(nameDll);

        if(!dll.load())
        {
            qDebug() << "Error : could not load " << nameDll;
            continue;
        }

        qDebug() << nameDll << " successfully loaded";

        GetPixels fct = (GetPixels)dll.resolve("drawShape");

        if (fct == nullptr)
        {
            dll.unload();
            continue;
        }

        areaShapes->addDrawMethod(nameDll.toStdString().substr(0, nameDll.length() - 4), fct);
    }
}
