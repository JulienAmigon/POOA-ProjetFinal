#include "SceneCursor.h"

SceneCursor::SceneCursor(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view) : Scene(x, y, w, h, view)
{
    QGraphicsRectItem* bgRect = new QGraphicsRectItem();
    bgRect->setRect(rect);
    bgRect->setBrush(QColor(200, 200, 200));
    scene->addItem(bgRect);

    //Ligne de séparation sous le rect de la zone de choix de curseur
    QGraphicsLineItem* line = new QGraphicsLineItem(x, y + h, x + w, y + h);
    line->setPen(QColor(0, 0, 0));
    scene->addItem(line);
}


SceneCursor::~SceneCursor()
{
    for (auto btn : buttonList)
    {
        delete btn;
    }
    scene->clear();
}


/***********************************************************************/
/* Méthode pour initialiser un nouveau bouton de couleur dans la scène */
/***********************************************************************/
void SceneCursor::addColorButton(std::string name, QColor color, Pointer *p, QWidget* parent)
{
    QPushButton* button = new QPushButton(QString(name.c_str()), parent);

    button->setGeometry(QRect(QPoint(50 * buttonList.size() + 10, 0), QSize(50, 50)));

    QAbstractButton::connect(button, &QPushButton::clicked, parent, [p, color]() {
        p->SetColor(color);
    });

    buttonList.push_back(button);
}
