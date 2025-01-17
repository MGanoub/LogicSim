#include "elementView.h"
#include "elementPort.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace UI::CircuitElements
{
    ElementView::ElementView(Core::Circuit::ElementType type, int inputPortCount, int outPutPortCount, int identifier, QGraphicsItem *parent)
        : QGraphicsObject(parent),
          m_type(type),
          m_inputPortsCount(inputPortCount),
          m_outPutPortCount(outPutPortCount),
          m_identifier(identifier),
          m_pixmapWidth(64),
          m_pixmapHeight(64),
          m_maxPortsToDisplayOnOneSide(6),
          m_resourceInfo(ResourceManager::getInstance().getResourceInformationOf(type))
    {
        setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        addPorts();
    }

    int ElementView::getId()
    {
        return m_identifier;
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
        if (isSelected())
        {

            const auto selectionBrush = QColor(175, 0, 0, 80);
            const auto selectionPen = QColor(175, 0, 0, 255);
            painter->setBrush(selectionBrush);
            painter->setPen(QPen(selectionPen, 0.5, Qt::SolidLine));
            painter->drawRoundedRect(boundingRect(), 5, 5);
        }

        painter->drawPixmap(QPoint(0, 0), *m_pixmap);
    }

    void ElementView::setPixmap(const QString &pixmapPath)
    {
        m_pixmap = new QPixmap(pixmapPath);
        m_pixmap->scaled(m_pixmapWidth, m_pixmapHeight, Qt::KeepAspectRatio);
    }

    void ElementView::addPorts()
    {
        for (int i = 0; i < m_inputPortsCount; i++)
        {
            {
                auto *port = new ElementPort(ElementPort::PortType::INPUTPORT, this);
                port->setIndex(i);
                int dt = m_pixmapHeight / m_inputPortsCount;
                int posY = (0.5 * dt) + (i * dt);
                port->setPos(0, posY);
                port->update();
                port->show();
            }
        }

        for (int i = 0; i < m_outPutPortCount; i++)
        {
            {
                auto *port = new ElementPort(ElementPort::PortType::OUTPUTPORT, this);
                // output port starting index is after the last index of  input port
                port->setIndex(i + m_inputPortsCount);
                port->setPos(m_pixmapWidth, m_pixmapHeight / 2);
                port->update();
                port->show();
            }
        }
    }

    void ElementView::setVisualState(Core::Circuit::State state)
    {
    }
}
