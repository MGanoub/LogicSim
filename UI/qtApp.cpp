#include "qtApp.h"
#include "UI/Controllers/mainGuiContainer.h"

namespace UI
{
    QtApp::QtApp()
        : m_appArgcount(0),
          m_app(std::make_unique<QApplication>(m_appArgcount, nullptr)),
          m_mainGuiContainer(std::make_unique<MainGuiContainer>())
    {
    }

    void QtApp::startGuiApp()
    {
        if (m_app == nullptr)
        {
            return;
        }
        m_mainGuiContainer->showMainWindow();
        m_app->exec();
    }

    QtApp &QtApp::getInstance()
    {
        static QtApp s_instance;
        return s_instance;
    }
}
