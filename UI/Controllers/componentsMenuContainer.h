#ifndef COMPONENTSMENUCONTAINER_H
#define COMPONENTSMENUCONTAINER_H

#include "UI/disp/Widgets/componentsMenuWidget.h"
#include "UI/disp/Widgets/listItemWidget.h"
#include <QTabWidget>
#include <memory>

namespace UI
{
    class ComponentModel;
    class ComponentsMenuContainer
    {
    public:
        enum ComponentMenuTabIndex
        {
            IC_TAB,
            LOGIC_TAB
        };
        ComponentsMenuContainer(ComponentModel *componentModel, QTabWidget *menuTabWidget);

    private:
        QTabWidget *m_menuViewWidget;
        std::unique_ptr<UI::CustomWidgets::ComponentsMenuWidget> m_sourceComponentMenuWidget;
        std::unique_ptr<UI::CustomWidgets::ComponentsMenuWidget> m_gatesComponentMenuWidget;
        // TODO:: do a search widget for searching elements
        // std::vector<UI::CustomWidgets::ListItemWidget *> m_icTabListItemWidgets;
        ComponentModel *m_componentModel;
        void populateComponentsMenu();
    };
}
#endif // COMPONENTSMENUCONTAINER_H
