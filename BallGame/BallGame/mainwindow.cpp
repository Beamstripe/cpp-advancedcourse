#include "mainwindow.h"
#include <QTextCodec>
#define tr QString::fromLocal8Bit
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("小球碰撞游戏"));
    splitter=new QSplitter(Qt::Horizontal,this); //水平切分
    left=new leftwidget(this);
    right=new rightwidget(this);
    splitter->addWidget(left);
    splitter->addWidget(right);
    splitter->setStretchFactor(0,1); //设置切分的默认比例， 1:4
    splitter->setStretchFactor(1,4);
    splitter->setStyleSheet("QSplitter::handle { background-color: gray }");
    splitter->setHandleWidth(10); //设置分割条的大小和样式
    this->setCentralWidget(splitter);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeToShow()));
    timer->start(100);
}
void MainWindow::timeToShow(){
    right->updateBalls();
}
void MainWindow::StopTimer(){
    timer->stop();
}
void MainWindow::resumeTimer(){
    timer->start(100);
}
MainWindow::~MainWindow()
{

}
