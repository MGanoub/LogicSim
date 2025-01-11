#include "mainwindow.h"
#include "Forms/ui_mainwindow.h"
#include "Widgets/scenewidget.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_scene = new sceneWidget(this);
    m_scene->setBackgroundBrush(QColor("#ffffe6"));
    ui->graphicsView->setScene(m_scene);

    populateComponentsMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateComponentsMenu()
{
    const auto listWidget = ui->icTab->findChild<QListWidget *>("icListWidget");
    if (listWidget == nullptr)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        QIcon icon(QPixmap(":/input/buttonOff.png"));
        auto *item = new QListWidgetItem(icon, QString("test"), listWidget, 0);
        listWidget->addItem(item);
    }
}
