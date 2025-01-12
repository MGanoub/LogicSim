#ifndef ELEMENTPORT_H
#define ELEMENTPORT_H

#include "elementView.h"
#include <QGraphicsPathItem>

namespace UI::CustomWidgets
{
    class ElementPort : public QGraphicsPathItem
    {
    public:
        enum
        {
            Type = QGraphicsItem::UserType + 1
        };
        explicit ElementPort(QGraphicsItem *parent = nullptr);
        void UpdateBrush();

        int type() const override
        {
            return Type;
        }

    private:
        int m_radius;
        int m_margin;

        ElementView *m_parent;
    };
}

#endif // ELEMENTPORT_H
