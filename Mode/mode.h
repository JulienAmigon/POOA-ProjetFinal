#ifndef MODE_H
#define MODE_H

#include "Headers.h"

using namespace std;

class Mode
{
public:
    Mode();
    virtual ~Mode() { }
    virtual string getMode() const = 0;
    virtual string getModeName() const = 0;
    //virtual QGraphicsItem* dessiner(QPoint, QColor) const = 0;
    virtual QGraphicsItem* action(QPoint, QColor) const = 0;

};

#endif // MODE_H
