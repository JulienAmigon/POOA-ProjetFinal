#include "SceneCursor.h"
#include "qgraphicsitem.h"

SceneCursor::SceneCursor(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view) : Scene(x, y, w, h, view)
{
    QGraphicsRectItem* bgRect = new QGraphicsRectItem();
    bgRect->setRect(rect);
    bgRect->setBrush(QColor(200, 200, 200));
    scene->addItem(bgRect);

    //Ligne de séparation sous le rect de la zone de choix de curseur
    QGraphicsLineItem* line = new QGraphicsLineItem(x, y + h, x + w, y + h);
    line->setPen(QColor(0, 0, 0));
    scene->addItem(line);

}


SceneCursor::~SceneCursor()
{
    scene->clear();
}
