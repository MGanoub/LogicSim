#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include "UI/disp/Widgets/sceneWidget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <vector>

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
    class SceneEditor : public QObject
    {
        Q_OBJECT
    public:
        explicit SceneEditor(QGraphicsView *graphicsViewWidget, QObject *parent = nullptr);

        bool eventFilter(QObject *obj, QEvent *evt) override;

    private:
        UI::CustomWidgets::sceneWidget *m_scene;
        QGraphicsView *m_graphicsView;
        UI::CircuitElements::ElementConnection *m_connection;
        bool m_isWireConnectionInProgress = false;
        QList<UI::CircuitElements::ElementConnection *> m_connectionsList;
        std::vector<UI::CircuitElements::ElementView *> m_circuitElements;
        Core::Circuit::CircuitManager *m_circuitManager;

        bool handleDropEvent(QEvent *event);
        bool handleMousePressEvent(QEvent *event);
        bool handleMouseMovementEvent(QEvent *event);
        bool handleMouseReleaseEvent(QEvent *event);

        bool handleKeyPressed(QEvent *event);

        QGraphicsItem *getSceneItemAtPos(const QPointF PosPoint);
        bool isItemAnElementPort(QGraphicsItem *item);

        void setConnectionInEdit(UI::CircuitElements::ElementConnection *connection);
        void removeConnectionInEdit();
        void removeConnection(UI::CircuitElements::ElementConnection *connection);
        void removeElement(UI::CircuitElements::ElementView *element);
        bool hasConnectionStarted();
        UI::CircuitElements::ElementConnection *getConnectionInEdit();
        void resetConnectionStatus();

        void updateElementsInScene();

        bool m_isItemSelected = false;
    };
}

#endif // SCENEEDITOR_H
