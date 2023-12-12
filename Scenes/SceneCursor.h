#ifndef SCENECURSOR_H
#define SCENECURSOR_H

#include "Scenes/Scene.h"

class SceneCursor : public Scene
{
public:
    SceneCursor() { }
    SceneCursor(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view);
    ~SceneCursor();

    void onClick(QPoint point, Pointer* pointer) override {
        qDebug() << point.x() << pointer->GetSize();    // Juste pour éviter les warnings
    }
};

#endif // SCENECURSOR_H
