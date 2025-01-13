#include "component.h"

namespace Core::Circuit
{
    Component::Component(Type type)
        : m_type(type)
    {
        static int s_uniqueIdentifier = 0;
        m_identifier = s_uniqueIdentifier++;
    }

    int Component::getIndentifier()
    {
        return m_identifier;
    }

    void Component::setType(Component::Type type)
    {
        m_type = type;
    }
    Component::Type Component::getType()
    {
        return m_type;
    }
}
