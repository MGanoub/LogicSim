#ifndef MAINGUICONTAINER_H
#define MAINGUICONTAINER_H

#include "UI/disp/mainwindow.h"
#include <memory>

namespace UI
{
    class MainGuiContainer
    {
    public:
        MainGuiContainer();
        void showMainWindow();

    private:
        std::unique_ptr<MainWindow> m_mainWindow;
        std::unique_ptr<UI::SceneEditor> m_sceneEditor;
    };
} // namespace UI
#endif // MAINGUICONTAINER_H
