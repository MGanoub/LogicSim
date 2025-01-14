#include "mainGuiContainer.h"

namespace UI
{
    MainGuiContainer::MainGuiContainer()
        : m_mainWindow(std::make_unique<MainWindow>()),
          m_sceneEditor(std::make_unique<SceneEditor>(m_mainWindow->getGraphicsViewWidget()))
    {
    }

    void MainGuiContainer::showMainWindow()
    {
        m_mainWindow->show();
    }
}
