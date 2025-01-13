#ifndef COMPONENT_H
#define COMPONENT_H

#include "Core/Circuit/Components/IComponent.h"

namespace Core::Circuit
{
    class Component : public IComponent
    {
    public:
        enum class Type
        {
            UNDEFINED,
            INPUT,
            LOGIC_GATE,
            OUTPUT
        };
        Component() = default;
        Component(Type type);
        Component(Component&& other);

        int getIndentifier() override;
        virtual void setType(Component::Type type);
        virtual Component::Type getType();

    private:
        int m_identifier;
        Type m_type;
    };
}
#endif // COMPONENT_H
