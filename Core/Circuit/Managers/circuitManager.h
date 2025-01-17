#ifndef CIRCUITMANAGER_H
#define CIRCUITMANAGER_H

#include "Core/Circuit/CircuitEnums.h"
#include "Core/Circuit/Components/component.h"
#include <memory>
#include <vector>

namespace Core::Circuit
{
    class CircuitManager
    {
    public:
        CircuitManager(CircuitManager const &) = delete;
        CircuitManager &operator=(CircuitManager const &) = delete;
        CircuitManager(CircuitManager const &&) = delete;
        CircuitManager &operator=(CircuitManager const &&) = delete;

        static CircuitManager &getInstance();

        int addComponent(ElementType type);
        bool removeComponent(int compIdentifier);
        bool addConnection(int firstCompIdent, int firstCompPortNumber, int secondCompIdent, int secondCompPortNumber);
        void updateCircuit();
        bool removeConnection(int firstCompIdent, int firstCompPortNumber, int secondCompIdent, int secondCompPortNumber);
        std::vector<Component *> getComponentsList();

    private:
        CircuitManager() = default;
        std::vector<std::unique_ptr<Component>> m_components;

        Component *getComponentById(int componentId);
    };
}

#endif // CIRCUITMANAGER_H
