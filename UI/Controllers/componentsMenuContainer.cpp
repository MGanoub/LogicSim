#include "componentsMenuContainer.h"
#include "Core/Circuit/CircuitEnums.h"
#include "UI/Managers/resourceManager.h"
#include "UI/Models/componentModel.h"
#include "UI/disp/Widgets/listItemWidget.h"
namespace UI
{
    ComponentsMenuContainer::ComponentsMenuContainer(ComponentModel *componentModel, QTabWidget *menuTabWidget)
        : m_menuViewWidget(menuTabWidget),
          m_componentModel(componentModel),
          m_sourceComponentMenuWidget(std::make_unique<UI::CustomWidgets::ComponentsMenuWidget>()),
          m_gatesComponentMenuWidget(std::make_unique<UI::CustomWidgets::ComponentsMenuWidget>())
    {
        if (m_menuViewWidget == nullptr || m_sourceComponentMenuWidget == nullptr || m_gatesComponentMenuWidget == nullptr)
        {
            return;
        }
        m_menuViewWidget->addTab(m_sourceComponentMenuWidget.get(), QIcon(UI::ResourceManager::getInstance().getSourceCompTabIconPath()), QString());
        m_menuViewWidget->addTab(m_gatesComponentMenuWidget.get(), QIcon(UI::ResourceManager::getInstance().getLogicGateTabIconPath()), QString());

        m_menuViewWidget->setCurrentIndex(ComponentMenuTabIndex::IC_TAB);

        populateComponentsMenu();
    }

    void ComponentsMenuContainer::populateComponentsMenu()
    {
        const auto availableSourceComponents = m_componentModel->getAvailableSourceComponents();
        const auto availableLogicGateComponents = m_componentModel->getAvailableLogicGateComponents();
        for (auto component : availableSourceComponents)
        {
            const auto resourceInfo = UI::ResourceManager::getInstance().getResourceInformationOf(component);

            auto *listItem = new UI::CustomWidgets::ListItemWidget(QPixmap(resourceInfo.offStatePixmapPath), static_cast<int>(component), QString(resourceInfo.displayName), m_menuViewWidget);
            m_sourceComponentMenuWidget->addListItem(listItem);
        }
        for (auto component : availableLogicGateComponents)
        {
            const auto resourceInfo = UI::ResourceManager::getInstance().getResourceInformationOf(component);

            auto *listItem = new UI::CustomWidgets::ListItemWidget(QPixmap(resourceInfo.offStatePixmapPath), static_cast<int>(component), QString(resourceInfo.displayName), m_menuViewWidget);
            m_gatesComponentMenuWidget->addListItem(listItem);
        }
    }
}
