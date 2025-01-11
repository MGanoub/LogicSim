#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QGraphicsScene>
#include <QObject>

namespace UI
{

    class SceneEditor : public QObject
    {
        Q_OBJECT
    public:
        explicit SceneEditor(QObject *parent = nullptr, QGraphicsScene *scene = nullptr);

        bool eventFilter(QObject *obj, QEvent *evt) override;

    private:
        QGraphicsScene *m_scene;

        bool handleDropEvent(QGraphicsSceneDragDropEvent *event);
    };
}

#endif // SCENEEDITOR_H
