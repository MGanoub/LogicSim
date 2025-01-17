#ifndef COMPONENTSMENUWIDGET_H
#define COMPONENTSMENUWIDGET_H

#include "UI/disp/Widgets/listItemWidget.h"
#include <QIcon>
#include <QWidget>
#include <QtWidgets/QVBoxLayout>

namespace UI::CustomWidgets
{
    class ComponentsMenuWidget : public QWidget
    {
        Q_OBJECT
    public:
        explicit ComponentsMenuWidget(QWidget *parent = nullptr);
        void addListItem(ListItemWidget *listItemWidget);

    private:
        QVBoxLayout *m_verticalLayout;
        QSpacerItem *m_verticalSpacer;
    };
}

#endif // COMPONENTSMENUWIDGET_H
