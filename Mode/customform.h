#ifndef CUSTOMFORM_H
#define CUSTOMFORM_H

#include "mode.h"
#include "Forme/circle.h"
#include "Forme/square.h"
#include "Forme/triangle.h"

class CustomForm : public Mode
{
private:
    QList<Forme *> itemList;
public:
    CustomForm();
    string getMode() const override { return "Custom"; }
    string getModeName() const override { return "Mode custom"; }
    QGraphicsItem* action(QPoint, QColor) const override;

    CustomForm(QString filePath) {
        qDebug() << "Custom " << filePath;
        // Ouvrir la file associé (si numéro = 0, la première et si numéro = 2, la troisième)
        // Et remplir la liste GraphicsItem avec une ligne = un item

        QFile file(filePath);

        if (!file.open(QIODevice::ReadOnly))
            qDebug() << "CustomForm::Constructeur : " << filePath << "non ouvert";
        else
        {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                qDebug() << line;
                construire(line);
            }
            qDebug() << "";
        }
    }

    ~CustomForm() {
        for (int i = 0; i < itemList.size(); ++i) {
            delete itemList.at(i);
        }
    }

    //QGraphicsItem * construire(QString information) {
    void construire(QString information) {
        // Information du type "4 0 0 255 0 10"
        // Qui correspond à "Type de forme, rouge, bleu, vert, position X, position Y"
        Forme * forme;


        QStringList listWords = information.split(" ");    // Tout est séparé par des espaces

        QColor couleur(listWords.at(1).toInt(), listWords.at(2).toInt(), listWords.at(3).toInt());
        QRect rect(listWords.at(4).toInt(), listWords.at(5).toInt(), 20, 20);


        // type de la forme (5 = triangle (polygon), 4 = rond (ellipse), 3 = carré (rect)). Peut passer par QGraphicsRectItem::Type aussi
        switch(listWords.at(0).toInt()) {
        case 3:
            qDebug() << "carré";
            forme = new Square();
            break;
        case 4:
            qDebug() << "rond";
            forme = new Circle();
            qDebug() << forme->getModeName();
            break;
        case 5:
            qDebug() << "polygon";
            forme = new Triangle();
            break;
        default:
            qDebug() << "NOTHING";
            break;
        }


        delete forme;
        //return forme;
    }


};

#endif // CUSTOMFORM_H
