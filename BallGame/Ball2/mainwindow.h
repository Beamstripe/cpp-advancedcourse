#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QSplitter>
#include <QMainWindow>
#include "leftwidget.h"
#include "rightwidget.h"
#include<QTimer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void StopTimer();//停止定时器的接口
    void resumeTimer();//重新定时器的接口
    RightWidget* getRightWidget(){return right;}
protected slots:
    void timeToShow();//定时器事件对应的槽方法
private:
    LeftWidget *left;
    RightWidget *right;
    QSplitter *splitter;
    QTimer *timer;
};

#endif // MAINWINDOW_H
