
#include "Core/Circuit/Managers/circuitManager.h"
#include "Core/Circuit/Components/Input/VCCInput.h"
#include "Core/Circuit/Components/Output/led.h"
#include <algorithm>
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

    bool CircuitManager::addConnection(int firstCompIdent, int secondCompIdent, int secondCompPortNumber)
    {
        auto firstComp = std::find_if(m_components.begin(), m_components.end(), [&](Component *comp)
                                      { return (comp->getIndentifier() == firstCompIdent); });
        auto secondComp = std::find_if(m_components.begin(), m_components.end(), [&](Component *comp)
                                       { return comp->getIndentifier() == secondCompIdent; });
        if ((firstComp == m_components.end()) || (secondComp == m_components.end()))
        {
            return false;
        }
        auto *inputComp = static_cast<InputComponent *>(*firstComp);
        auto *outputComp = static_cast<OutputComponent *>(*secondComp);
        Port *outputPort = inputComp->getOutputPort();
        Port *inputPort = outputComp->getInputPortAtIndex(secondCompPortNumber);

        if (outputPort->isConnected() || inputPort->isConnected())
        {
            return false;
        }
        outputPort->connectTo(inputPort);
        inputPort->connectTo(outputPort);
        return true;
    }
    void CircuitManager::update()
    {
        for (auto *comp : m_components)
        {
            if (comp->getType() == Component::Type::OUTPUT)
            {
                auto *outputComp = static_cast<OutputComponent *>(comp);
                outputComp->computeOutputState();
            }
        }
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
