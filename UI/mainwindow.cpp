#include "mainwindow.h"
#include "Forms/ui_mainwindow.h"
#include "Widgets/listItemWidget.h"
#include "Widgets/sceneWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    UpdateGraphicViewScene();
    populateComponentsMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateGraphicViewScene()
{
    m_scene = new UI::CustomWidgets::sceneWidget(this);
    m_scene->setBackgroundBrush(QColor("#ffffe6"));
    ui->graphicsView->setScene(m_scene);
    m_editor = new UI::SceneEditor(this, m_scene);
}

void MainWindow::populateComponentsMenu()
{
    const auto icTabLayout = ui->icTab->layout();
    icTabLayout->removeItem(ui->icTabVerticalSpacer);
    if (icTabLayout == nullptr)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        auto *item = new UI::CustomWidgets::ListItemWidget(QPixmap(":/inputs/VCC.png"), 10, QString("VCC"), this);
        icTabLayout->addWidget(item);
    }
    icTabLayout->addItem(ui->icTabVerticalSpacer);
    /*
    auto *spaceItem = new QSpacerItem(20, 40);
    icTabLayout->addItem(spaceItem);
    */
}

QGraphicsScene *MainWindow::getSceneWidget()
{
    return m_scene;
}
