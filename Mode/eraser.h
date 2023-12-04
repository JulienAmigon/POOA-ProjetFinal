#ifndef ERASER_H
#define ERASER_H

#include "mode.h"

class Eraser : public Mode
{
public:
    Eraser();
    string getMode() const override { return "Effaceur"; }
    string getModeName() const override { return "Mode effaceur"; }
    QGraphicsItem* action(QPoint, QColor) const override;
};

#endif // ERASER_H
