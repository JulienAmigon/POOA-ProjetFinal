#ifndef FENETRE1_H
#define FENETRE1_H

#include "Headers.h"
#include "Scenes/Scene.h"
class FenetreGraph : public QWidget
{
    Q_OBJECT
private:
    std::vector<Scene*> scenes;
    QGraphicsScene* scene;
    QGraphicsView* view;
    Pointer* pointer;

public:
    explicit FenetreGraph(QWidget* parent = nullptr);
    ~FenetreGraph();

    void mousePressEvent(QMouseEvent* event);
};

#endif // FENETRE1_H
