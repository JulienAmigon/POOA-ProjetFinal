#include "pointer.h"

Pointer::Pointer()
{
    getPixels = nullptr;
}


std::vector<QPoint> Pointer::GetPixels(QPoint point)
{
    if (getPixels == nullptr)           // Une barrière pour éviter les erreurs
        return std::vector<QPoint>();

    return (*getPixels)(point, size);
}
