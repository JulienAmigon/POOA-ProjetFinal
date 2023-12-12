#ifndef FENETRE1_H
#define FENETRE1_H

#include "Scenes/Scene.h"
#include "Scenes/SceneCursor.h"
#include "Scenes/ScenePixels.h"
#include "Scenes/SceneShapes.h"

class FenetreGraph : public QWidget
{
    Q_OBJECT
private:
    // Scène et vue principales de la fenêtre
    QGraphicsScene* scene;
    QGraphicsView* view;

    // Les différentes scènes qui contiennent les éléments
    SceneCursor* areaCursor;
    ScenePixels* areaPixels;
    SceneShapes* areaShapes;

    Pointer* pointer;

    // Chemin et liste de boutons des formes persos
    QString path = QDir().currentPath()+"/Plugins";
    QList<QPushButton *> buttonListPerso;


    // Les couleurs
    QPushButton *buttonRed;
    QPushButton *buttonYellow;
    QPushButton *buttonBlue;
    QPushButton *buttonPlus;
    QPushButton *buttonMinus;

    void LoadDlls();

    /*
    void loadFormesPerso();     // Charge le dossier de .dll
    void loadForme(QString);    // Charge la fonction du .dll QString
*/
public:
    explicit FenetreGraph(QWidget* parent = nullptr);
    ~FenetreGraph();

    QString getPath() { return path; }


    void changeColorBlue() { pointer->SetColor(Qt::blue); }
    void changeColorRed() { pointer->SetColor(Qt::red); }
    void changeColorYellow() { pointer->SetColor(Qt::yellow); }


    void mousePressEvent(QMouseEvent* event);
};

std::vector<QPoint> carre(QPoint, int);
std::vector<QPoint> cercle(QPoint, int);

#endif // FENETRE1_H
