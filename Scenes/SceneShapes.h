#ifndef SCENESHAPES_H
#define SCENESHAPES_H

#include "Scenes/Scene.h"
#include "qwidget.h"
class SceneShapes : public Scene
{
public:
    SceneShapes() { }
    SceneShapes(qreal x, qreal y, qreal w, qreal h, QWidget* parent);
    ~SceneShapes();
};

#endif // SCENESHAPES_H
