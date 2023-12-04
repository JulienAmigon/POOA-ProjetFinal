#ifndef FENETRE_H
#define FENETRE_H

#include "ModeHeaders.h"

class Fenetre : public QWidget
{
    Q_OBJECT
private:
    Mode *m = nullptr;
    Forme *f = nullptr;

    Pointeur *p;
    QPushButton *buttonPointeur;
    Eraser *e;
    QPushButton *buttonEraser;

    Square *s;
    QPushButton *buttonSquare;
    Circle *c;
    QPushButton *buttonCircle;
    Triangle *t;
    QPushButton *buttonTriangle;

    CustomForm *custom;


    QList<QPushButton *> buttonList;


    QColor couleur;
    QPushButton *buttonRed;
    QPushButton *buttonYellow;
    QPushButton *buttonBlue;

    QPushButton *buttonSave;
    QPushButton *buttonLoad;

    QGraphicsScene * scene;
    QGraphicsView * view;

public:
    explicit Fenetre(QWidget *parent = nullptr);
    ~Fenetre() {
        delete p;
        delete e;
        delete s;
        delete t;
        //delete custom;
        delete buttonPointeur;
        delete buttonSquare;
        delete buttonCircle;
        delete buttonRed;
        delete buttonYellow;
        delete buttonBlue;
        for (int i = 0; i < buttonList.size(); ++i) {
            delete buttonList.at(i);
        }
        scene->clear();    // On fait bien attention à vider la scene avant de fermer
        delete scene;
        delete view;
    }
    QGraphicsScene * getScene() { return scene; }
    QGraphicsView * getView() { return view; }


    void switchMode(Mode *mode) {
        m = mode;
        std::cout << m->getModeName() << std::endl;
    }

    void switchPointeurMode() { switchMode(p); }
    void switchEraserMode() { switchMode(e); }
    void switchSquareMode() { switchMode(s); }
    void switchCircleMode() { switchMode(c); }
    void switchTriangleMode() { switchMode(t); }

    void lecture(QString path);

    void saveForm();

    void loadForm();


    void createFile(QString pathFile, QList<QGraphicsItem *> list);

    void listFormesPerso();

    void switchModePerso(QString fileName) {
        qDebug() << "button " << fileName;

        QString filePath = QDir().currentPath()+"/FormesPerso/"+fileName;

        custom = new CustomForm(filePath);
        m = custom;
        delete custom;
    }




    // Affiche tout les X de la liste de formes
    void afficheListeQGraphics(QList<QGraphicsItem *> list) {
        for (qsizetype i = 0; i < list.size(); ++i) {
            int x = list.value(i)->boundingRect().topLeft().x();
            cout << x << endl;
        }

    }




    void mousePressEvent(QMouseEvent *);
    void Affichage(QGraphicsItem *);

signals:
    void onClick(QPoint);
public slots:
    void changeColor(QColor color) { couleur = color; }
};

#endif // FENETRE_H
