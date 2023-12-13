#include "fenetre.h"


int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    FenetreGraph mainWindow;
    mainWindow.show();



    return app.exec();
}
