#include "logicSimApp.h"

namespace LogicSim
{

}
LogicSimApp::LogicSimApp()
    : m_guiApp(UI::QtApp::getInstance())
{
    m_guiApp.startGuiApp();
}
