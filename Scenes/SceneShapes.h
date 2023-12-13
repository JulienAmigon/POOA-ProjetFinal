#ifndef SCENESHAPES_H
#define SCENESHAPES_H

#include "Scenes/Scene.h"

typedef std::vector<QPoint> (*GetPixels)(QPoint, int);

class SceneShapes : public Scene
{
private:
    std::map<std::string, GetPixels> methodDictionary;      // Pour savoir quelle méthode
    std::vector<QPushButton*> buttonList;                   // Liste de boutons des formes importées
public:
    SceneShapes() { }
    SceneShapes(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view);
    ~SceneShapes();

    void onClick(QPoint point, Pointer* pointer) override {
        qDebug() << point.x() << pointer->GetSize();    // Juste pour éviter les warnings
    }
    
    void addDrawMethod(std::string, GetPixels);
    GetPixels getDrawMethod(std::string);

    void createNewButton(std::string, GetPixels, Pointer*, QWidget*);
};

#endif // SCENESHAPES_H
