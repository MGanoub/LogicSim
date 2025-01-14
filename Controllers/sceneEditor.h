#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include "UI/Widgets/sceneWidget.h"
#include <QGraphicsScene>
#include <QObject>
#include <vector>
namespace Core::Circuit
{
    class CircuitManager;
}
namespace UI
{
    namespace CustomWidgets
    {
        class ElementView;
        class ElementConnection;
    }
    class SceneEditor : public QObject
    {
        Q_OBJECT
    public:
        explicit SceneEditor(QObject *parent = nullptr);

        bool eventFilter(QObject *obj, QEvent *evt) override;

    private:
        UI::CustomWidgets::sceneWidget *m_scene;
        UI::CustomWidgets::ElementConnection *m_connection;
        bool m_isWireConnectionInProgress = false;
        QList<UI::CustomWidgets::ElementConnection *> m_connectionsList;
        std::vector<UI::CustomWidgets::ElementView *> m_circuitElements;
        Core::Circuit::CircuitManager *m_circuitManager;

        bool handleDropEvent(QEvent *event);
        bool handleMousePressEvent(QEvent *event);
        bool handleMouseMovementEvent(QEvent *event);
        bool handleMouseReleaseEvent(QEvent *event);

        QGraphicsItem *getSceneItemAtPos(const QPointF PosPoint);
        bool isItemAnElementPort(QGraphicsItem *item);

        void setConnectionInEdit(UI::CustomWidgets::ElementConnection *connection);
        void removeConnection();
        bool hasConnectionStarted();
        UI::CustomWidgets::ElementConnection *getConnectionInEdit();
        void resetConnectionStatus();

        void updateElementsInScene();
    };
}

#endif // SCENEEDITOR_H
