#ifndef ELEMENTPORT_H
#define ELEMENTPORT_H

#include "elementView.h"
#include <QGraphicsPathItem>

namespace UI::CustomWidgets
{
    class ElementPort : public QGraphicsPathItem
    {
    public:
        explicit ElementPort(QGraphicsItem *parent = nullptr);

    private:
        int m_radius;
        int m_margin;

        ElementView *m_parent;
    };
}

#endif // ELEMENTPORT_H
