#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include "../UI/Widgets/sceneWidget.h"
#include <QGraphicsScene>
#include <QObject>

namespace UI
{

    class SceneEditor : public QObject
    {
        Q_OBJECT
    public:
        explicit SceneEditor(QObject *parent = nullptr);

        bool eventFilter(QObject *obj, QEvent *evt) override;

    private:
        UI::CustomWidgets::sceneWidget *m_scene;

        bool handleDropEvent(QEvent *event);
        bool handleMousePressEvent(QEvent *event);
        QGraphicsItem *getSceneItemAtPos(const QPointF PosPoint);
        bool isItemAnElementPort(QGraphicsItem *item);
    };
}

#endif // SCENEEDITOR_H
