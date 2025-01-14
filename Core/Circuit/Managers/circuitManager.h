#ifndef CIRCUITMANAGER_H
#define CIRCUITMANAGER_H

#include "Core/Circuit/Components/component.h"
#include "Core/Circuit/elementTypeEnum.h"
#include <memory>
#include <vector>
#include "Core/Circuit/Components/Output/outputComponent.h"

namespace Core::Circuit
{
    class CircuitManager
    {
    public:
        CircuitManager();
        ~CircuitManager();

        int addComponent(ElementType type);
        bool addConnection(int firstCompIdent, int secondCompIdent, int secondCompPortNumber);
        void update();
        std::vector<Component *> getComponentsList();
        std::vector<OutputComponent *> getOutputComponentsList();

    private:
        std::vector<Component *> m_components;
    };
}

#endif // CIRCUITMANAGER_H
