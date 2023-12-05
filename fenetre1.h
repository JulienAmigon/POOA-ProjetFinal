#ifndef FENETRE1_H
#define FENETRE1_H

#include "Headers.h"
#include "Scenes/Scene.h"
class FenetreGraph : public QWidget
{
    Q_OBJECT
private:
    Scene** scenes;

public:
    FenetreGraph() { }
    FenetreGraph(QWidget* parent);
    ~FenetreGraph();
};

#endif // FENETRE1_H
