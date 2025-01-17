#include "componentsMenuContainer.h"
#include "Core/Circuit/CircuitEnums.h"
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
        auto *vccItem = new UI::CustomWidgets::ListItemWidget(QPixmap(":/inputs/VCC.png"), static_cast<int>(Core::Circuit::ElementType::VCC), QString("VCC"), m_menuViewWidget);
        auto *gndItem = new UI::CustomWidgets::ListItemWidget(QPixmap(":/inputs/GND.png"), static_cast<int>(Core::Circuit::ElementType::GND), QString("GND"), m_menuViewWidget);

        auto *ledItem = new UI::CustomWidgets::ListItemWidget(QPixmap(":/outputs/WhiteLedOff.png"), static_cast<int>(Core::Circuit::ElementType::LED), QString("LED"), m_menuViewWidget);
        auto *andGate = new UI::CustomWidgets::ListItemWidget(QPixmap(":/LogicGates/ANDGate.png"), static_cast<int>(Core::Circuit::ElementType::AND_GATE), QString("AND Gate"), m_menuViewWidget);
        auto *orGate = new UI::CustomWidgets::ListItemWidget(QPixmap(":/LogicGates/ORGate.png"), static_cast<int>(Core::Circuit::ElementType::OR_GATE), QString("OR Gate"), m_menuViewWidget);
        m_componentMenuWidget->addListItem(vccItem);
        m_componentMenuWidget->addListItem(gndItem);
        m_componentMenuWidget->addListItem(ledItem);
        m_componentMenuWidget->addListItem(andGate);
        m_componentMenuWidget->addListItem(orGate);

        m_icTabListItemWidgets.push_back(vccItem);
    }
}
