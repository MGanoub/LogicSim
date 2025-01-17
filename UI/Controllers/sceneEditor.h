#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include "Common/IObserver.h"
#include "UI/disp/Widgets/sceneWidget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <vector>
#include "Core/Circuit/CircuitEnums.h"

namespace Core::Circuit
{
    class CircuitManager;
}
namespace UI
{
    namespace CircuitElements
    {
        class ElementView;
        class ElementConnection;
    }
    class SceneEditor : public QObject, Common::IObserver
    {
        Q_OBJECT
        enum class EventState
        {
            INITIAL,
            ELEMENT_SELECTED,
            CONNECTION_STARTED
        };

    public:
        explicit SceneEditor(QGraphicsView *graphicsViewWidget, QObject *parent = nullptr);

        bool eventFilter(QObject *obj, QEvent *evt) override;
        void circuitChanged() override;

    private:
        UI::CustomWidgets::sceneWidget *m_scene;
        QGraphicsView *m_graphicsView;
        UI::CircuitElements::ElementConnection *m_connection;
        QList<UI::CircuitElements::ElementConnection *> m_connectionsList;
        std::vector<UI::CircuitElements::ElementView *> m_circuitElements;
        EventState m_currentEventState;
        UI::CircuitElements::ElementView *m_pressedElement;

        bool handleDropEvent(QEvent *event);
        bool handleMousePressEvent(QEvent *event);
        bool handleMouseMovementEvent(QEvent *event);
        bool handleMouseReleaseEvent(QEvent *event);

        bool handleKeyPressed(QEvent *event);

        QGraphicsItem *getSceneItemAtPos(const QPointF PosPoint);
        bool isItemAnElementPort(QGraphicsItem *item);

        void startConnection(QGraphicsItem *item);
        void setConnectionInEdit(UI::CircuitElements::ElementConnection *connection);
        void removeConnectionInEdit();

        void addConnection(QGraphicsItem *item);
        void addElement(int type, QPointF dragPos);
        void removeConnection(UI::CircuitElements::ElementConnection *connection);
        void removeElement(UI::CircuitElements::ElementView *element);
        bool hasConnectionStarted();
        UI::CircuitElements::ElementConnection *getConnectionInEdit();
        void resetConnectionStatus();
        void updateElementState(UI::CircuitElements::ElementView *element, Core::Circuit::State state);

        void selectElementConnections(QGraphicsItem *item);
    };
}

#endif // SCENEEDITOR_H
