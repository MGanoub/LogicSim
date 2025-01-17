#include "componentsMenuWidget.h"

namespace UI::CustomWidgets
{
    ComponentsMenuWidget::ComponentsMenuWidget(QWidget *parent)
        : QWidget{parent},
          m_verticalLayout(new QVBoxLayout(this)),
          m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding))
    {

        setObjectName("icTab");
        setCursor(QCursor(Qt::ArrowCursor));
        m_verticalLayout->setSpacing(15);
        m_verticalLayout->setContentsMargins(-1, 2, -1, 2);
        m_verticalLayout->addItem(m_verticalSpacer);
    }

    void ComponentsMenuWidget::addListItem(ListItemWidget *listItemWidget)
    {
        m_verticalLayout->removeItem(m_verticalSpacer);
        m_verticalLayout->addWidget(listItemWidget);
        m_verticalLayout->addItem(m_verticalSpacer);
    }
}
