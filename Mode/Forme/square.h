#ifndef SQUARE_H
#define SQUARE_H

#include "forme.h"

class Square : public Forme
{
public:
    Square();
    string getMode() const override { return "Carre"; }
    string getModeName() const override { return "Mode carre"; }

    QGraphicsItem* dessiner(QPoint p, QColor c) const override {
        QGraphicsRectItem * r = new QGraphicsRectItem();
        r->setRect(p.x(), p.y(), getTailleX(), getTailleY());
        r->setBrush(c);

        return r;
    }

};

#endif // SQUARE_H
