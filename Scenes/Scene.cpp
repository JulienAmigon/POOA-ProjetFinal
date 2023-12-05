#include "Scene.h"
#include "qgraphicsview.h"

Scene::Scene(qreal x, qreal y, qreal w, qreal h, QWidget* parent)
{
    try
    {
        scene = new QGraphicsScene(x, y, w, h);
        view = new QGraphicsView(parent);
        view->setScene(scene);
    }
    catch(_exception e)
    {
        qDebug() << "Error init Scene";
    }
}

Scene::~Scene()
{
    delete view;
    delete scene;
}


bool Scene::isCursorInScene(int x, int y)
{
    return scene->sceneRect().contains(x, y);
}
