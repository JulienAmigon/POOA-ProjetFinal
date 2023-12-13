#ifndef FENETRE_H
#define FENETRE_H

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

    // Chemin des plugins
    QString path = QDir().currentPath()+"/Plugins";

    //plus, minus
    QPushButton *buttonPlus;
    QPushButton *buttonMinus;

    void LoadDlls();
public:
    explicit FenetreGraph(QWidget* parent = nullptr);
    ~FenetreGraph();

    QString getPath() { return path; }
    SceneCursor* getAreaCursor() { return areaCursor; }
    ScenePixels* getAreaPixels() { return areaPixels; }
    SceneShapes* getAreaShape() { return areaShapes; }

    void mousePressEvent(QMouseEvent* event);
};

std::vector<QPoint> carre(QPoint, int);
std::vector<QPoint> cercle(QPoint, int);

#endif // FENETRE_H




/*
void savePlugin();
void createFile(QString);
*/

/*
void FenetreGraph::savePlugin()
{
    // Accès au dossier "Plugin" et demande à ajouter un truc
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save File"),
                                                    getPath(),
                                                    tr("All Files (*)"));

    // Ajoute un fichier
    if(!fileName.isEmpty()) {
        createFile(fileName);
    }
    else
        qDebug() << "Fenetre::saveForm : Le nom du fichier est vide" << fileName;
}

void FenetreGraph::createFile(QString pathFile)
{
    QFile file(pathFile);
    if (file.open(QIODevice::ReadWrite)) {
        // Pour écrire le contenu dans le fichier
        QTextStream stream(&file);

        stream << "Ne rien faire";
    }
    else
        qDebug() << "Fenetre::createFile : Impossible d'accéder au fichier :" << pathFile;


    file.close();
}
*/
