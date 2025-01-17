#ifndef MAINGUICONTAINER_H
#define MAINGUICONTAINER_H

#include "UI/Controllers/ComponentsMenuContainer.h"
#include "UI/Controllers/sceneEditor.h"
#include "UI/disp/mainwindow.h"
#include <memory>

namespace UI
{
    class ComponentModel;
    class MainGuiContainer
    {
    public:
        MainGuiContainer(ComponentModel *componentModel);
        void showMainWindow();

    private:
        std::unique_ptr<MainWindow> m_mainWindow;
        std::unique_ptr<UI::SceneEditor> m_sceneEditor;
        std::unique_ptr<ComponentsMenuContainer> m_componentsMenuContainer;
    };
} // namespace UI
#endif // MAINGUICONTAINER_H
