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

    QString path = QDir().currentPath()+"/FormesPerso";
    QList<QPushButton *> buttonListPerso;


    QPushButton *buttonRed;
    QPushButton *buttonYellow;
    QPushButton *buttonBlue;
    QPushButton *triangle;

public:
    explicit FenetreGraph(QWidget* parent = nullptr);
    ~FenetreGraph();

    QString getPath() { return path; }


    void loadFormesPerso();     // Charge le dossier de .dll
    void loadForme(QString);    // Charge la fonction du .dll QString


    void changeColorBlue() { pointer->SetColor(Qt::blue); }
    void changeColorRed() { pointer->SetColor(Qt::red); }
    void changeColorYellow() { pointer->SetColor(Qt::yellow); }


    void mousePressEvent(QMouseEvent* event);
};

#endif // FENETRE1_H
