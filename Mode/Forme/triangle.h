#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "forme.h"

class Triangle : public Forme
{
public:
    Triangle();
    string getMode() const override { return "Triangle"; }
    string getModeName() const override { return "Mode triangle"; }
    QGraphicsItem* dessiner(QPoint, QColor) const override;
};

#endif // TRIANGLE_H
