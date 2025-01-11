#include "listItemWidget.h"
#include <QHBoxLayout>

namespace UI::CustomWidgets
{

    ListItemWidget::ListItemWidget(const QPixmap &pixmap, int type, const QString &icFileName, QWidget *parent)
        : QFrame(parent), m_draggableLabel(new DraggableLabel(pixmap, type, icFileName, this)), m_nameLabel(new QLabel(icFileName, this))
    {
        auto *itemLayout = new QHBoxLayout();
        itemLayout->setSpacing(6);
        itemLayout->setObjectName(QStringLiteral("itemLayout"));

        setLayout(itemLayout);
        itemLayout->addWidget(m_draggableLabel);
        itemLayout->addStretch();
        itemLayout->addWidget(m_nameLabel);
        itemLayout->addStretch();
    }

    QLabel *ListItemWidget::getDraggableLabel() const
    {
        return m_draggableLabel;
    }

    void ListItemWidget::mousePressEvent(QMouseEvent *)
    {
        m_draggableLabel->startDrag();
    }

}
