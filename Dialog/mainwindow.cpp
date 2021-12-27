#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <cmath>
#include <QLayout>
#include <QString>
#include <QStatusBar>
#include <QMenuBar>
#include <QTextCodec>

#define Tr QString::fromLocal8Bit
MainWindow::~MainWindow(){}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    setWindowTitle(Tr("简单窗口程序"));
    centerWidget=new CenterWidget(this);
    //设置焦点 ***
    centerWidget->setFocusPolicy(Qt::StrongFocus);

    setCentralWidget(centerWidget);
    QDesktopWidget* desktop = QApplication::desktop();
    resize(desktop->width()/2,desktop->height()/2);
    move((desktop->width() - this->width())/2,
         (desktop->height() - this->height())/2);
    //文件菜单
    fileMenu=menuBar()->addMenu(Tr("文件"));
    exitAction=new QAction(Tr("退出"),this);
    exitAction->setShortcut(Tr("Ctrl+X"));
    exitAction->setStatusTip(Tr("退出程序"));
    fileMenu->addAction(exitAction);
    lineAction=new QAction(QIcon("line.gif"),Tr("线条"),this);
    lineAction->setShortcut(Tr("Ctrl+L"));
    lineAction->setStatusTip(Tr("绘制线条"));
    ellipseAction=new QAction(QIcon("ellipse.gif"),Tr("椭圆"),this);
    ellipseAction->setShortcut(Tr("Ctrl+E"));
    ellipseAction->setStatusTip(Tr("绘制椭圆"));
    rectangleAction=new QAction(QIcon("rectangle.gif"),Tr("矩形"),this);
    rectangleAction->setShortcut(Tr("Ctrl+R"));
    rectangleAction->setStatusTip(Tr("绘制矩形"));
    //"颜色"菜单
    colorMenu=menuBar()->addMenu(Tr("颜色"));

    colorBlackAction=new QAction(Tr("Black"),this);
    colorBlackAction->setStatusTip(Tr("黑色"));
    colorBlackAction->setCheckable(true);
    colorBlackAction->setChecked(true);
    colorMenu->addAction(colorBlackAction);

    colorGreenAction=new QAction(Tr("Green"),this);
    colorGreenAction->setStatusTip(Tr("绿色"));
    colorGreenAction->setCheckable(true);
    colorGreenAction->setChecked(false);
    colorMenu->addAction(colorGreenAction);

    colorYellowAction=new QAction(Tr("Yellow"),this);
    colorYellowAction->setStatusTip(Tr("黄色"));
    colorYellowAction->setCheckable(true);
    colorYellowAction->setChecked(false);
    colorMenu->addAction(colorYellowAction);
    colorMenu->addSeparator();

    ifFilledAction=new QAction(Tr("Fill"),this);
    ifFilledAction->setStatusTip(Tr("图形填充"));
    ifFilledAction->setCheckable(true);
    ifFilledAction->setChecked(false);
    colorMenu->addAction(ifFilledAction);
    //"绘制"菜单
    drawMenu=this->menuBar()->addMenu(Tr("绘图"));
    drawMenu->addAction(lineAction);
    drawMenu->addAction(ellipseAction);
    drawMenu->addAction(rectangleAction);
    //"绘制"状态栏
    drawToolBar=addToolBar(Tr("Draw"));
    drawToolBar->addAction(lineAction);
    drawToolBar->addAction(ellipseAction);
    drawToolBar->addAction(rectangleAction);
    statusBar()->show();

    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(lineAction,SIGNAL(triggered()),this,SLOT(line()));
    connect(ellipseAction,SIGNAL(triggered()),this,SLOT(ellipse()));
    connect(rectangleAction,SIGNAL(triggered()),this,SLOT(rectangle()));

    connect(colorBlackAction,SIGNAL(triggered()),this,SLOT(changeToBlack()));
    connect(colorGreenAction,SIGNAL(triggered()),this,SLOT(changeToGreen()));
    connect(colorYellowAction,SIGNAL(triggered()),this,SLOT(changeToYellow()));
    connect(ifFilledAction,SIGNAL(triggered()),this,SLOT(changeFilled()));
}
void MainWindow::line(){
    centerWidget->setDrawType(0);
    centerWidget->update();
}
void MainWindow::ellipse(){
    centerWidget->setDrawType(1);
    centerWidget->update();
}
void MainWindow::rectangle(){
    centerWidget->setDrawType(2);
    centerWidget->update();
}
void MainWindow::changeFilled(){
    bool temp=ifFilledAction->isChecked();
    ifFilledAction->setChecked(~temp);
    centerWidget->setFilled(temp);
    centerWidget->update();
}
void MainWindow::changeToBlack(){
    if(colorYellowAction->isChecked())
        colorYellowAction->setChecked(false);
    else if(colorGreenAction->isChecked())
        colorGreenAction->setChecked(false);
    colorBlackAction->setChecked(true);
    centerWidget->setShapeColor("black");
    centerWidget->update();
}
void MainWindow::changeToGreen(){
    if(colorYellowAction->isChecked())
        colorYellowAction->setChecked(false);
    else if(colorBlackAction->isChecked())
        colorBlackAction->setChecked(false);
    colorGreenAction->setChecked(true);
    centerWidget->setShapeColor("green");
    centerWidget->update();
}
void MainWindow::changeToYellow(){
    if(colorBlackAction->isChecked())
        colorBlackAction->setChecked(false);
    else if(colorGreenAction->isChecked())
        colorGreenAction->setChecked(false);
    colorYellowAction->setChecked(true);
    centerWidget->setShapeColor("yellow");
    centerWidget->update();
}
