#ifndef POINTER_H
#define POINTER_H

#include "../Headers.h"

class Pointer
{
protected:
    int size;                                           // Taille du dessin
    QColor color;                                       // Couleur du dessin
    std::vector<QPoint> (*getPixels)(QPoint, int);      // Le dessin, sous forme de pointeur de fonction

public:
    Pointer();

    // Les méthodes de Pointer ne sont que des getteur/setteur
    void SetDrawMethod(std::vector<QPoint>(*method)(QPoint, int)) { getPixels = method; }
    std::vector<QPoint> GetPixels(QPoint);

    int GetSize() { return size; }
    void SetSize(int s) { size = std::max(s, 1); }

    QColor GetColor() { return color; }
    void SetColor(QColor c) { color = c; }
};

#endif // POINTER_H
