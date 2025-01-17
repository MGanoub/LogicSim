#ifndef COMPONENTMODEL_H
#define COMPONENTMODEL_H

#include "Core/Circuit/CircuitEnums.h"
#include <vector>

namespace UI
{
    class ComponentModel
    {
    public:
        ComponentModel() = default;
        std::vector<Core::Circuit::ElementType> getAvailableSourceComponents();
        std::vector<Core::Circuit::ElementType> getAvailableLogicGateComponents();
    };
}
#endif // COMPONENTMODEL_H
