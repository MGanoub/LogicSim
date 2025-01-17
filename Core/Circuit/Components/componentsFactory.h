#ifndef COMPONENTSFACTORY_H
#define COMPONENTSFACTORY_H

#include "Core/Circuit/CircuitEnums.h"
#include "Core/Circuit/Components/component.h"
#include <memory>

namespace Core::Circuit
{
    class ComponentsFactory
    {
    public:
        ComponentsFactory(ComponentsFactory const &) = delete;
        ComponentsFactory &operator=(ComponentsFactory const &) = delete;
        ComponentsFactory(ComponentsFactory const &&) = delete;
        ComponentsFactory &operator=(ComponentsFactory const &&) = delete;

        static ComponentsFactory &getInstance();
        std::unique_ptr<Component> createComponent(ElementType type);

    private:
        ComponentsFactory() = default;
    };
}
#endif // COMPONENTSFACTORY_H
