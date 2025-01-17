#include "mainGuiContainer.h"

namespace UI
{
    MainGuiContainer::MainGuiContainer(ComponentModel *componentModel)
        : m_mainWindow(std::make_unique<MainWindow>()),
          m_sceneEditor(std::make_unique<SceneEditor>(m_mainWindow->getGraphicsViewWidget())),
          m_componentsMenuContainer(std::make_unique<ComponentsMenuContainer>(componentModel, m_mainWindow->getComponentsTabWidget()))
    {
    }

    void MainGuiContainer::showMainWindow()
    {
        m_mainWindow->show();
    }
}
