
#include "Core/Circuit/Managers/circuitManager.h"
#include "Core/Circuit/Components/componentsFactory.h"
#include <algorithm>

namespace Core::Circuit
{
    CircuitManager::CircuitManager()
    {
    }

    CircuitManager::~CircuitManager()
    {
    }

    int CircuitManager::addComponent(ElementType type)
    {
        if (type == ElementType::UNKNOWN)
        {
            int unknownIdentifier = 0;
            return unknownIdentifier;
        }
        auto comp = ComponentsFactory::getInstance().createComponent(type);
        const auto compIdentifier = comp->getIndentifier();
        m_components.push_back(std::move(comp));
        return compIdentifier;
    }

    Component *CircuitManager::getComponentById(int componentId)
    {

        for (auto &comp : m_components)
        {
            if (comp->getIndentifier() == componentId)
            {
                return comp.get();
            }
        }
        return nullptr;
    }

    bool CircuitManager::addConnection(int firstCompIdent, int firstCompPortNumber, int secondCompIdent, int secondCompPortNumber)
    {
        auto *firstComp = getComponentById(firstCompIdent);
        auto *secondComp = getComponentById(secondCompIdent);

        if ((firstComp == nullptr) || (secondComp == nullptr))
        {
            return false;
        }
        auto *firstPort = firstComp->getPortAtIndex(firstCompPortNumber);
        auto *secondPort = secondComp->getPortAtIndex(secondCompPortNumber);

        if (firstPort->isConnected() || secondPort->isConnected() ||
            (firstPort->isInputType() && secondPort->isInputType()) ||
            (firstPort->isOutputType() && secondPort->isOutputType()))
        {
            return false;
        }
        firstPort->connectTo(secondPort);
        secondPort->connectTo(firstPort);
        updateCircuit();
        return true;
    }

    bool CircuitManager::removeConnection(int firstCompIdent, int firstCompPortNumber, int secondCompIdent, int secondCompPortNumber)
    {
        auto *firstComp = getComponentById(firstCompIdent);
        auto *secondComp = getComponentById(secondCompIdent);

        if ((firstComp == nullptr) || (secondComp == nullptr))
        {
            return false;
        }
        auto *firstPort = firstComp->getPortAtIndex(firstCompPortNumber);
        auto *secondPort = secondComp->getPortAtIndex(secondCompPortNumber);

        if (!firstPort->isConnected() || !secondPort->isConnected())
        {
            return false;
        }
        firstPort->disconnect();
        secondPort->disconnect();
        updateCircuit();
        return true;
    }

    void CircuitManager::updateCircuit()
    {
        for (auto &comp : m_components)
        {
            for (auto &comp : m_components)
            {
                comp->computeOutputState();
            }
        }
    }
    std::vector<Component *> CircuitManager::getComponentsList()
    {
        std::vector<Component *> comps;
        for (auto &comp : m_components)
        {
            comps.push_back(comp.get());
        }
        return comps;
    }
}
