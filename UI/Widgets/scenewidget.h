#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QGraphicsScene>

class sceneWidget : public QGraphicsScene
{
public:
    explicit sceneWidget(QObject *parent = nullptr);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    static constexpr int m_gridSize = 16;
};

#endif // SCENEWIDGET_H
