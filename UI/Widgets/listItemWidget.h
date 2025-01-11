#ifndef LISTITEMWIDGET_H
#define LISTITEMWIDGET_H

#include "draggableLabel.h"
#include <QFrame>
#include <QLabel>

namespace UI::CustomWidgets
{
    class ListItemWidget : public QFrame
    {
        Q_OBJECT
    private:
        DraggableLabel *m_draggableLabel;
        QLabel *m_nameLabel;

    public:
        explicit ListItemWidget(const QPixmap &pixmap, int elementType, const QString &icFileName, QWidget *parent = nullptr);

        QLabel *getDraggableLabel() const;

    protected:
        void mousePressEvent(QMouseEvent *event) override;
    };

}
#endif // LISTITEMWIDGET_H
