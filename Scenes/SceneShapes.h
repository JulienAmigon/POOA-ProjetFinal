#ifndef SCENESHAPES_H
#define SCENESHAPES_H

#include "Scenes/Scene.h"
#include "qwidget.h"
class SceneShapes : public Scene
{
public:
    SceneShapes() { }
    SceneShapes(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view);
    ~SceneShapes();

    void onClick(QPoint point, Pointer* pointer) override { };
};

#endif // SCENESHAPES_H
