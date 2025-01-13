
#include "Core/Circuit/Managers/circuitManager.h"
#include "Core/Circuit/Components/Input/VCCInput.h"
#include "Core/Circuit/Components/Output/led.h"
namespace Core::Circuit
{
    CircuitManager::CircuitManager()
    {
    }

    CircuitManager::~CircuitManager()
    {
        for (auto *comp : m_components)
        {
            delete comp;
        }
    }

    int CircuitManager::addComponent(ElementType type)
    {
        int identifier = -1;
        switch (type)
        {
        case ElementType::VCC:
        {
            const auto comp = new VCCInput();
            identifier = comp->getIndentifier();
            m_components.push_back(comp);
            break;
        }
        case ElementType::LED:
        {
            const auto comp = new LED();
            identifier = comp->getIndentifier();
            m_components.push_back(comp);
            break;
        }
        default:
            break;
        }
        return identifier;
    }

    void CircuitManager::addConnection(int firstCompIdent, int firstCompPortNumber, int secondCompIdent, int secondCompPortNumber)
    {
    }
    void CircuitManager::update()
    {
    }

    std::vector<Component *> CircuitManager::getComponentsList()
    {
        return m_components;
    }

}

/*


void CircuitManager::addConnection(int firstComponentIdent, int firstCompPortNumber, int secondCompIdent, int secondCompPortNumber)
{
    auto *firstComp = std::find(== ident) auto *secondComp = std::find(second);
    if (firstCmp != &&second)
    {
        return false;
    }
    Port p1 = firstComp.getPort();
    Port p2 = secondComp.getPort();
    p1->connectTo(p2);
    p2->connectTo(p1);
    return true;
}

::startSimluation()
{
    m_simulator.start();
}
::pauseSimulation()
{
    m_simulator.pause();
}

notifyListeners()
{
    for (listeners : listeners)
    {
        listener.update();
    }
}
*/
