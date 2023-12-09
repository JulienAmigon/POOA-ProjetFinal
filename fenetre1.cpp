#include "fenetre1.h"
#include "Scenes/SceneCursor.h"
#include "Scenes/ScenePixels.h"
#include "Scenes/SceneShapes.h"

FenetreGraph::FenetreGraph(QWidget* parent) : QWidget{parent}
{
    float w = 1280;
    float h = 720;
    setFixedSize(w, h);

    scene = new QGraphicsScene(0, 0, w, h);
    view = new QGraphicsView(scene, this);

    view->setAlignment(Qt::AlignCenter);


    scenes.push_back(new SceneCursor(0, 0, w, 0.2*h, view));
    scenes.push_back(new ScenePixels(0.3*w, 0.2*h, 0.7*w, 0.8*h, view));
    scenes.push_back(new SceneShapes(0, 0.2*h, 0.3*w, 0.8*h, view));


    pointer = new Pointer();
    pointer->SetColor(QColor(255, 0, 0));
    pointer->SetSize(3);
    pointer->SetDrawMethod([] (QPoint point, int size) -> std::vector<QPoint> {
        std::vector<QPoint> pixels;

        for (int i = -size + 1; i < size; i++)
        {
            for (int j = -size + 1; j < size; j++)
            {
                pixels.push_back(point + QPoint(i, j));
            }
        }

        return pixels;
    });
}


FenetreGraph::~FenetreGraph()
{
    for (auto s : scenes)
    {
        delete s;
    }
}


void FenetreGraph::mousePressEvent(QMouseEvent* event)
{
    QPoint point = event->pos();

    for (auto s : scenes)
    {
        if (s->isCursorInScene(point))
        {
            s->onClick(point, pointer);
        }
    }
}
