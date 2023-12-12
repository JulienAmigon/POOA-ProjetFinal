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

    QList<QPushButton *> buttonListPerso;


    QPushButton *buttonRed;
    QPushButton *buttonYellow;
    QPushButton *buttonBlue;
    QPushButton *triangle;

public:
    explicit FenetreGraph(QWidget* parent = nullptr);
    ~FenetreGraph();


    void loadFormesPerso();
    void FormesPerso(QString);


    void changeColorBlue() { pointer->SetColor(Qt::blue); }
    void changeColorRed() { pointer->SetColor(Qt::red); }
    void changeColorYellow() { pointer->SetColor(Qt::yellow); }

    void changeTriangle();

    void mousePressEvent(QMouseEvent* event);
};

#endif // FENETRE1_H
