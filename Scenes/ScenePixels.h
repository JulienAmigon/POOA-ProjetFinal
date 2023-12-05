#ifndef SCENEPIXELS_H
#define SCENEPIXELS_H

#include "Scenes/Scene.h"
#include "qwidget.h"
class ScenePixels : public Scene
{
public:
    ScenePixels() { }
    ScenePixels(qreal x, qreal y, qreal w, qreal h, QWidget* parent);
    ~ScenePixels();
};


#endif // SCENEPIXELS_H
