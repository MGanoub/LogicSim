#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QGraphicsScene>
#include <QObject>
#include "../UI/Widgets/sceneWidget.h"

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

        bool handleDropEvent(QGraphicsSceneDragDropEvent *event);
    };
}

#endif // SCENEEDITOR_H
