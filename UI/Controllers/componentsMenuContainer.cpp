#include "componentsMenuContainer.h"
#include "UI/disp/Widgets/listItemWidget.h"
namespace UI
{
    ComponentsMenuContainer::ComponentsMenuContainer(QTabWidget *menuTabWidget)
        : m_menuViewWidget(menuTabWidget),
          m_componentMenuWidget(new UI::CustomWidgets::ComponentsMenuWidget())
    {
        if (m_menuViewWidget == nullptr || m_componentMenuWidget == nullptr)
        {
            return;
        }
        m_menuViewWidget->addTab(m_componentMenuWidget, *m_componentMenuWidget->getIcon(), QString());
        m_menuViewWidget->setCurrentIndex(ComponentMenuTabIndex::IC_TAB);

        populateComponentsMenu();
    }

    void ComponentsMenuContainer::populateComponentsMenu()
    {
        auto *vccItem = new UI::CustomWidgets::ListItemWidget(QPixmap(":/inputs/VCC.png"), 10, QString("VCC"), m_menuViewWidget);
        auto *ledItem = new UI::CustomWidgets::ListItemWidget(QPixmap(":/outputs/WhiteLedOff.png"), 11, QString("LED"), m_menuViewWidget);
        m_componentMenuWidget->addListItem(vccItem);
        m_componentMenuWidget->addListItem(ledItem);
        // m_componentMenuWidget->addListItem(ui->icTabVerticalSpacer);

        m_icTabListItemWidgets.push_back(vccItem);
    }
}
