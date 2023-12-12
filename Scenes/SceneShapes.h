#ifndef SCENESHAPES_H
#define SCENESHAPES_H

#include "Scenes/Scene.h"
#include <QPushButton>

typedef std::vector<QPoint> (*GetPixels)(QPoint, int);

class SceneShapes : public Scene
{
private:
    std::map<std::string, GetPixels> methodDictionary;
    std::vector<QPushButton*> buttonList;
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
