#include "SceneShapes.h"
#include "qgraphicsitem.h"

SceneShapes::SceneShapes(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view) : Scene(x, y, w, h, view)
{
    QGraphicsRectItem* bgRect = new QGraphicsRectItem();
    bgRect->setRect(rect);
    bgRect->setBrush(QColor(200, 200, 200));
    scene->addItem(bgRect);

    //Ligne de séparation à droite de la zone de choix de forme
    QGraphicsLineItem* line = new QGraphicsLineItem(x + w, y, x + w, y + h);
    line->setPen(QColor(0, 0, 0));
    scene->addItem(line);
}


SceneShapes::~SceneShapes()
{
    methodDictionary.clear();

    for (auto btn : buttonList)
    {
        delete btn;
    }
}


void SceneShapes::addDrawMethod(std::string key, GetPixels value)
{
    methodDictionary.insert({key, value});
}


GetPixels SceneShapes::getDrawMethod(std::string key)
{
    GetPixels method = nullptr;

    // Cherche un élément de clé 'key', puis vérifie qu'il en a trouvé un
    if (auto search = methodDictionary.find(key); search != methodDictionary.end())
    {
        method = search->second;
    }

    return method;
}


void SceneShapes::createNewButton(std::string name, GetPixels fct, Pointer* pointer, QWidget* parent)
{
    QPushButton* button = new QPushButton(QString(name.c_str()), parent);

    float buttonHeight = 0.05 * rect.height();

    button->setGeometry(
        rect.left(),
        rect.top() + buttonHeight * buttonList.size() + 10,
        rect.width(),
        buttonHeight
    );

    QAbstractButton::connect(button, &QPushButton::clicked, parent, [pointer, fct]() {
        pointer->SetDrawMethod(fct);
    });

    buttonList.push_back(button);
}

