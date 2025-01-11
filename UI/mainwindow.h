#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "../Controllers/sceneEditor.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

namespace CustomWidgets
{
    class sceneWidget;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene *getSceneWidget();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;
    UI::SceneEditor* m_editor;

    void populateComponentsMenu();
    void UpdateGraphicViewScene();
};
#endif // MAINWINDOW_H
