#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QLabel>

namespace UI::CustomWidgets
{
    class DraggableLabel : public QLabel
    {
        Q_OBJECT
    public:
        explicit DraggableLabel(QWidget *parent = nullptr);
        DraggableLabel(const QPixmap &pixmap, int type, const QString &name, QWidget *parent = nullptr);

        void startDrag(QPoint pos = QPoint());
        QString name() const;
        void setName(const QString &name);

        const QPixmap &pixmapData() const;
        void setPixmapData(const QPixmap &pixmapData);

    protected:
        void mousePressEvent(QMouseEvent *event) override;

    private:
        QPixmap m_pixmapData;
        QString m_name;
        int m_type;
    };
}
#endif // DRAGGABLELABEL_H
