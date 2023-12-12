#include "fenetre.h"


int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    FenetreGraph mainWindow;
    mainWindow.show();



    return app.exec();
}

/*


    Dessin dessin(&window);
    dessin.setup();

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);

    for(int i : v) {
        cout << i << endl;
    }


    QGraphicsRectItem r;
    r.setRect(50,250, 50, 50);


    r.setBrush(Qt::red);*/
