#ifndef ELEMENTPORT_H
#define ELEMENTPORT_H

#include "elementView.h"
#include <QGraphicsPathItem>

namespace UI::CircuitElements
{
    class ElementPort : public QGraphicsPathItem
    {
    public:
        enum
        {
            GraphicalType = QGraphicsItem::UserType + 1
        };

        enum class PortType
        {
            INPUTPORT,
            OUTPUTPORT
        };

        explicit ElementPort(PortType type, ElementView *parent = nullptr);
        void updateBrush();

        int type() const override;
        PortType getPortType();
        ElementView *getParent();
        void setIndex(int portNumber);
        int getIndex();
        void connected();
        void disconnected();

    private:
        int m_radius;
        int m_margin;
        int m_index;
        PortType m_portType;

        ElementView *m_parent;
    };
}

#endif // ELEMENTPORT_H
