#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "centerwidget.h"
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QToolBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CenterWidget *centerWidget;
    QMenu* fileMenu;
    QMenu* drawMenu;
    QAction* exitAction;
    QAction* lineAction;
    QAction* ellipseAction;
    QAction* rectangleAction;
    QToolBar* drawToolBar;
    QLabel* keyPressedLabel;
protected slots:
    void line();
    void ellipse();
    void rectangle();
};
//MainWindow::~MainWindow(){

//}

#endif // MAINWINDOW_H
