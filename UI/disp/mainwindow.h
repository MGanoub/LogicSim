#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE
namespace UI
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        QGraphicsView *getGraphicsViewWidget();
        QTabWidget *getComponentsTabWidget();

    private:
        Ui::MainWindow *ui;
    };
}
#endif // MAINWINDOW_H
