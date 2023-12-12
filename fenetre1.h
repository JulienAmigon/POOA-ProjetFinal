#ifndef FENETRE1_H
#define FENETRE1_H

#include "Scenes/Scene.h"
#include "Scenes/SceneCursor.h"
#include "Scenes/ScenePixels.h"
#include "Scenes/SceneShapes.h"
#include <QWidget>
#include <QLibrary>

class FenetreGraph : public QWidget
{
    Q_OBJECT
private:
    QGraphicsScene* scene;
    QGraphicsView* view;

    SceneCursor* areaCursor;
    ScenePixels* areaPixels;
    SceneShapes* areaShapes;
    Pointer* pointer;

    void LoadDlls();

public:
    explicit FenetreGraph(QWidget* parent = nullptr);
    ~FenetreGraph();

    void mousePressEvent(QMouseEvent* event);
};

std::vector<QPoint> carre(QPoint, int);
std::vector<QPoint> cercle(QPoint, int);

#endif // FENETRE1_H
