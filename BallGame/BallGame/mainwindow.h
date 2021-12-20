#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include "leftwidget.h"
#include "rightwidget.h"
#include <QTimer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    rightwidget* getRightWidget(){return right;}
    void StopTimer(); //停止定时器的接口
    void resumeTimer(); //重启定时器的接口
protected slots:
    void timeToShow();
private:
    leftwidget *left;
    rightwidget *right;
    QSplitter *splitter;
    QTimer *timer; //定时器对象
};

#endif // MAINWINDOW_H
