#include "fenetre1.h"
#include "Scenes/SceneCursor.h"
#include "Scenes/ScenePixels.h"
#include "Scenes/SceneShapes.h"

FenetreGraph::FenetreGraph(QWidget* parent) : QWidget{parent}
{
    scenes = new Scene*[3];
    scenes[0] = new SceneCursor();
    scenes[1] = new ScenePixels();
    scenes[2] = new SceneShapes();
}
