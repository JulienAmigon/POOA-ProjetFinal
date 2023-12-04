#ifndef POINTEUR_H
#define POINTEUR_H

#include "mode.h"

class Pointeur : public Mode
{
public:
    Pointeur();
    string getMode() const override { return "Pointeur"; }
    string getModeName() const override { return "Mode pointage"; }
    QGraphicsItem* action(QPoint, QColor) const override;
};

#endif // POINTEUR_H

