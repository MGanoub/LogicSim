#include "scenewidget.h"
#include <QPainter>

sceneWidget::sceneWidget(QObject *parent)
    : QGraphicsScene(parent)
{
}

void sceneWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QGraphicsScene::drawBackground(painter, rect);
    painter->setPen(QPen(QColor(Qt::darkGray)));
    qreal left = int(rect.left()) - (int(rect.left()) % m_gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % m_gridSize);
    QVector<QPointF> points;
    for (qreal x = left; x < rect.right(); x += m_gridSize)
    {
        for (qreal y = top; y < rect.bottom(); y += m_gridSize)
        {
            points.append(QPointF(x, y));
        }
    }
    painter->drawPoints(points.data(), points.size());
}
