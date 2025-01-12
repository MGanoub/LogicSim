#include "elementView.h"
#include "elementPort.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace UI::CustomWidgets
{
    ElementView::ElementView(Core::Circuit::ElementType type, int inputPortCount, QGraphicsItem *parent)
        : QGraphicsObject(parent), m_type(type), m_inputPortsCount(inputPortCount)
    {
        addPorts();
    }

    QRectF ElementView::boundingRect() const
    {
        if (m_pixmap == nullptr)
        {
            return QRectF();
        }
        return m_pixmap->rect();
    }

    void ElementView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(widget)
        painter->setClipRect(option->exposedRect);
        /*
        if (isSelected())
        {
            painter->setBrush(m_selectionBrush);
            painter->setPen(QPen(m_selectionPen, 0.5, Qt::SolidLine));
            painter->drawRoundedRect(boundingRect(), 5, 5);
        }
        */
        painter->drawPixmap(QPoint(0, 0), *m_pixmap);
    }

    void ElementView::setPixmap(const QString &pixmapPath)
    {
        m_pixmap = new QPixmap(pixmapPath);
    }

    void ElementView::addPorts()
    {
        for (int i = 0; i < m_inputPortsCount; i++)
        {
            {
                auto *port = new ElementPort(this);
                // port->setGraphicElement(this);
                port->setPos(32, 0);
                port->update();
                // updatePorts();
                port->show();
            }
        }
    }

    void ElementView::updatePortsPosition()
    {

        int step = qMax(32 / m_inputPortsCount, 6);
        // int x = 32 - m_inputs.size() * step + step;
        // port->setPos(32, 0);
        // port->update();
    }
}
