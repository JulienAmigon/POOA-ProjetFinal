#ifndef SCENEPIXELS_H
#define SCENEPIXELS_H

#include "Scenes/Scene.h"

class ScenePixels : public Scene
{
private:
    int lines, columns;

    float borderX, borderY;
    float size;

    float offset;

    QRectF graphRectsRect;

    std::vector<QGraphicsRectItem*> graphRects;

    void SetBorders();
    void SetPixels();

    QPoint GetRectGridPoint(QPointF point);
    QPointF GetRectRealPoint(QPoint point);

public:
    ScenePixels() { }
    ScenePixels(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view);
    ~ScenePixels();

    void SetPixelsNumber(int l, int c, float offS);

    void onClick(QPoint point, Pointer* pointer) override;
};


#endif // SCENEPIXELS_H
