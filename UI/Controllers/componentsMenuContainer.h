#ifndef COMPONENTSMENUCONTAINER_H
#define COMPONENTSMENUCONTAINER_H

#include "UI/disp/Widgets/componentsMenuWidget.h"
#include "UI/disp/Widgets/listItemWidget.h"
#include <QTabWidget>

namespace UI
{
    class ComponentsMenuContainer
    {
    public:
        enum ComponentMenuTabIndex
        {
            IC_TAB,
            LOGIC_TAB
        };
        ComponentsMenuContainer(QTabWidget *menuTabWidget);

    private:
        QTabWidget *m_menuViewWidget;
        UI::CustomWidgets::ComponentsMenuWidget *m_componentMenuWidget;
        std::vector<UI::CustomWidgets::ListItemWidget *> m_icTabListItemWidgets;
        void populateComponentsMenu();
    };
}
#endif // COMPONENTSMENUCONTAINER_H
