#include "Scene.h"

Scene::Scene(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view)
{
    rect = QRectF(x, y, w, h);
    this->view = view;
    scene = view->scene();
}

Scene::~Scene()
{

}


bool Scene::isCursorInScene(QPoint point)
{
    return rect.contains(point);
}
