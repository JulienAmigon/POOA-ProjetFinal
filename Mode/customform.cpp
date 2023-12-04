#include "customform.h"

CustomForm::CustomForm() {}

QGraphicsItem *CustomForm::action(QPoint, QColor) const
{
    cout << "Frere c'est custom" << endl;

    return nullptr;
}
