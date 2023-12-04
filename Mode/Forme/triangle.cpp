#include "triangle.h"

Triangle::Triangle() {}

QGraphicsItem *Triangle::dessiner(QPoint p, QColor c) const
{
    // Taille
    int x = getTailleX();
    int y = getTailleY();

    QPolygon triangle;
    //triangle << QPoint(25, 0) << QPoint(0, 50) << QPoint(50, 50);
    triangle << QPoint( p.x() + x/2  ,   p.y() )
             << QPoint( p.x()        ,   p.y() + y )
             << QPoint( p.x() + x    ,   p.y() + y );

    QGraphicsPolygonItem *r = new QGraphicsPolygonItem(triangle);
    r->setBrush(c);

    return r;
}
