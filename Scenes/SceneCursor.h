#ifndef SCENECURSOR_H
#define SCENECURSOR_H

#include "Scenes/Scene.h"

class SceneCursor : public Scene
{
private :
    std::vector<QPushButton*> buttonList;   // Liste des boutons de couleur
public:
    SceneCursor() { }
    SceneCursor(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view);
    ~SceneCursor();

    void addColorButton(std::string name, QColor color, Pointer *p, QWidget* parent);

    void onClick(QPoint point, Pointer* pointer) override {
        qDebug() << point.x() << pointer->GetSize();    // Juste pour éviter les warnings
    }
};

#endif // SCENECURSOR_H
