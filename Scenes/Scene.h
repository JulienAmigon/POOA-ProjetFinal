#ifndef SCENE_H
#define SCENE_H

#include "Pointer/pointer.h"
#include "qgraphicsscene.h"
class Scene
{
protected:
    QRectF rect;
    QGraphicsView* view;
    QGraphicsScene* scene;
public:
    Scene() { }
    Scene(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view);
    virtual ~Scene();
  
    QGraphicsScene* getScene() { return scene; }

    bool isCursorInScene(QPoint point);
    virtual void onClick(QPoint point, Pointer* pointer) = 0;
};

#endif // SCENE_H
