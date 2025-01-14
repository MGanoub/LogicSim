#include "mainwindow.h"
#include "Forms/ui_mainwindow.h"
#include "Widgets/listItemWidget.h"
#include "Widgets/sceneWidget.h"

namespace UI
{
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    QGraphicsView *MainWindow::getGraphicsViewWidget()
    {
        return ui->graphicsView;
    }

    QTabWidget *MainWindow::getComponentsTabWidget()
    {
        return ui->componentsTabWidget;
    }
}
