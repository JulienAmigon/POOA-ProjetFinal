#include "SceneShapes.h"
#include "qgraphicsitem.h"

SceneShapes::SceneShapes(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view) : Scene(x, y, w, h, view)
{
    QGraphicsRectItem* bgRect = new QGraphicsRectItem();
    bgRect->setRect(rect);
    bgRect->setBrush(QColor(200, 200, 200));
    scene->addItem(bgRect);

    //Ligne de séparation à droite de la zone de choix de forme
    QGraphicsLineItem* line = new QGraphicsLineItem(x + w, y, x + w, y + h);
    line->setPen(QColor(0, 0, 0));
    scene->addItem(line);
}


SceneShapes::~SceneShapes()
{

}
