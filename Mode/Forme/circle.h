#ifndef CIRCLE_H
#define CIRCLE_H

#include "forme.h"

class Circle : public Forme
{
public:
    Circle();
    string getMode() const override { return "Cercle"; }
    string getModeName() const override { return "Mode cercle"; }
    QGraphicsItem* dessiner(QPoint, QColor) const override;
};

#endif // CIRCLE_H
