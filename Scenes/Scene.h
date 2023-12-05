#ifndef SCENE_H
#define SCENE_H

#include "qgraphicsscene.h"
class Scene
{
protected:
    QGraphicsScene* scene;
    QGraphicsView* view;

public:
    Scene() { }
    Scene(qreal x, qreal y, qreal w, qreal h, QWidget* parent);
    ~Scene();

    bool isCursorInScene(int x, int y);
    virtual void onClick(int x, int y);
};

#endif // SCENE_H
