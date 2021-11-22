#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Simple Visual Program"));
    centerWidget=new CenterWidget(this);
    setCentralWidget(centerWidget);
    QDesktopWidget* desktop = QApplication::desktop();
    resize(desktop->width()/2,desktop->height()/2);
    move((desktop->width() - this->width())/2,
      (desktop->height() - this->height())/2);
    fileMenu=menuBar()->addMenu(tr("File"));
    exitAction=new QAction(tr("Exit"),this);
    exitAction->setShortcut(tr("Ctrl+X"));
    exitAction->setStatusTip(tr("exit"));
    fileMenu->addAction(exitAction);
    lineAction=new QAction(QIcon("line.gif"),tr("line"),this);
    lineAction->setShortcut(tr("Ctrl+L"));
    lineAction->setStatusTip(tr("line"));
    ellipseAction=new QAction(QIcon("ellipse.gif"),tr("ellipse"),this);
    ellipseAction->setShortcut(tr("Ctrl+E"));
    ellipseAction->setStatusTip(tr("ellipse"));
    rectangleAction=new QAction(QIcon("rectangle.gif"),tr("rectangle"),this);
    rectangleAction->setShortcut(tr("Ctrl+R"));
    rectangleAction->setStatusTip(tr("rectangle"));
    keyPressedLabel=new QLabel();
    keyPressedLabel->setAlignment(Qt::AlignCenter);
    keyPressedLabel->show();
    statusBar()->addPermanentWidget(keyPressedLabel);
    drawMenu=this->menuBar()->addMenu(tr("paint"));
    drawMenu->addAction(lineAction);
    drawMenu->addAction(ellipseAction);
    drawMenu->addAction(rectangleAction);
    drawToolBar=addToolBar(tr("Draw"));
    drawToolBar->addAction(lineAction);
    drawToolBar->addAction(ellipseAction);
    drawToolBar->addAction(rectangleAction);

    statusBar()->show();
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(lineAction,SIGNAL(triggered()),this,SLOT(line()));
    connect(ellipseAction,SIGNAL(triggered()),this,SLOT(ellipse()));
    connect(rectangleAction,SIGNAL(triggered()),this,SLOT(rectangle()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::line(){
}
void MainWindow::ellipse(){
}
void MainWindow::rectangle(){
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    keyPressedLabel->setFixedSize(200,200);
    keyPressedLabel->setText("Pressed: "+event->text());
    keyPressedLabel->setToolTip(event->text());

//    if(event->key()==Qt::Key_W){
//        keyPressedLabel->setText(QString("W Pressed"));

//    }else if(event->key()==Qt::Key_A){
//        keyPressedLabel->setText(QString("A Pressed"));

//    }else if(event->key()==Qt::Key_S){
//        keyPressedLabel->setText(QString("S Pressed"));

//    }else if(event->key()==Qt::Key_D){
//        keyPressedLabel->setText(QString("D Pressed"));

//    }else ignore();

    update();
}
