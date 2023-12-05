#ifndef SCENECURSOR_H
#define SCENECURSOR_H

#include "Scenes/Scene.h"
#include "qwidget.h"
class SceneCursor : public Scene
{
public:
    SceneCursor() { }
    SceneCursor(qreal x, qreal y, qreal w, qreal h, QWidget* parent);
    ~SceneCursor();
};

#endif // SCENECURSOR_H
