#ifndef FORME_H
#define FORME_H

#include "../mode.h"

class Forme : public Mode
{
private :
    int tailleX = 50;
    int tailleY = 50;
    int posX = 0;
    int posY = 0;
    QColor color = Qt::black;
    QGraphicsItem * item = nullptr;
public:
    Forme();
    int getTailleX() const { return tailleX; }
    int getTailleY() const { return tailleY; }

    virtual QGraphicsItem* dessiner(QPoint, QColor) const = 0;

    QGraphicsItem* action(QPoint p, QColor c) const override {
        return dessiner(p, c);
    }


    Forme(int x, int y, QColor colour) {
        posX = x;
        posY = y;
        color = colour;
    }

    void dessinScene(QGraphicsScene * scene) {
        scene->addItem(item);
    }
};

#endif // FORME_H
