#include "ScenePixels.h"


ScenePixels::ScenePixels(qreal x, qreal y, qreal w, qreal h, QGraphicsView* view) : Scene(x, y, w, h, view)
{
    QGraphicsRectItem* bgRect = new QGraphicsRectItem();
    bgRect->setRect(rect);
    bgRect->setBrush(QColor(180, 180, 180));
    scene->addItem(bgRect);

    SetPixelsNumber(50, 50, 10);
}


ScenePixels::~ScenePixels()
{
    scene->clear();
}


void ScenePixels::SetPixelsNumber(int l, int c, float offS)
{
    lines = l; columns = c;
    offset = offS;

    SetBorders();
    SetPixels();
}


void ScenePixels::SetBorders()
{
    float sizeX = (rect.width() - 2 * offset) / columns;
    float sizeY = (rect.height() - 2 * offset) / lines;

    size = std::min(sizeX, sizeY);

    borderX = (rect.width() - size * columns) / 2;
    borderY = (rect.height() - size * lines) / 2;

    graphRectsRect = QRectF(rect.x() + borderX, rect.y() + borderY, columns * size, lines * size);
}


void ScenePixels::SetPixels()
{
    //scene->clear();
    //scene->setBackgroundBrush(QColor(180, 180, 180));
    for (auto graphRect : graphRects)
    {
        scene->removeItem(graphRect);
        delete graphRect;
    }
    graphRects.clear();

    for (int i = 0; i < columns; i++)
    {
        float x = rect.x() + borderX + i * size;

        for (int j = 0; j < lines; j++)
        {
            float y = rect.y() + borderY + j * size;

            QGraphicsRectItem* graphRect = new QGraphicsRectItem();
            graphRect->setRect(x, y, size, size);
            graphRect->setBrush(QColor(255, 255, 255));

            scene->addItem(graphRect);
            graphRects.push_back(graphRect);
        }
    }
}


void ScenePixels::onClick(QPoint point, Pointer* pointer)
{
    if (!graphRectsRect.contains(point) || pointer == nullptr)
        return;

    std::vector<QPoint> pixels = pointer->GetPixels(GetRectGridPoint(point));

    for (QPoint p : pixels)
    {
        QPointF pixelPoint = GetRectRealPoint(p);

        if (graphRectsRect.contains(pixelPoint))
        {
            QGraphicsRectItem* graphRect;
            QPointF sceneCoords = view->mapToScene(QPoint(pixelPoint.x(), pixelPoint.y()));
            graphRect = (QGraphicsRectItem*)scene->itemAt(sceneCoords, view->transform());

            graphRect->setBrush(pointer->GetColor());
        }
    }
}


QPoint ScenePixels::GetRectGridPoint(QPointF point)
{
    QPointF gridPoint = (point - graphRectsRect.topLeft()) / size;

    return QPoint(gridPoint.x(), gridPoint.y());
}


QPointF ScenePixels::GetRectRealPoint(QPoint point)
{
    return graphRectsRect.topLeft() + size * QPointF(point.x() + 0.5, point.y() + 0.5);
}
