#include "circle.h"

Circle::Circle() {}

QGraphicsItem* Circle::dessiner(QPoint p, QColor c) const
{
    QGraphicsEllipseItem* r = new QGraphicsEllipseItem();
    r->setRect(p.x(), p.y(), getTailleX(), getTailleY());
    r->setBrush(c);

    return r;
}

