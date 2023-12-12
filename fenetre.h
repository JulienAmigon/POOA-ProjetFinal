#ifndef FENETRE_H
#define FENETRE_H

#include "Scenes/Scene.h"
#include "Scenes/SceneCursor.h"
#include "Scenes/ScenePixels.h"
#include "Scenes/SceneShapes.h"
#include <QWidget>
#include <QLibrary>
#include "Headers.h"
#include "Scenes/Scene.h"

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

std::vector<QPoint> carre(QPoint, int);
std::vector<QPoint> cercle(QPoint, int);

#endif // FENETRE_H
