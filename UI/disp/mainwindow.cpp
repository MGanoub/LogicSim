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
        populateComponentsMenu();
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::populateComponentsMenu()
    {
        const auto icTabLayout = ui->icTab->layout();
        icTabLayout->removeItem(ui->icTabVerticalSpacer);
        if (icTabLayout == nullptr)
        {
            return;
        }

        auto *vccItem = new UI::CustomWidgets::ListItemWidget(QPixmap(":/inputs/VCC.png"), 10, QString("VCC"), this);
        auto *ledItem = new UI::CustomWidgets::ListItemWidget(QPixmap(":/outputs/WhiteLedOff.png"), 11, QString("LED"), this);
        icTabLayout->addWidget(vccItem);
        icTabLayout->addWidget(ledItem);
        icTabLayout->addItem(ui->icTabVerticalSpacer);
    }

    QGraphicsView *MainWindow::getGraphicsViewWidget()
    {
        return ui->graphicsView;
    }
}