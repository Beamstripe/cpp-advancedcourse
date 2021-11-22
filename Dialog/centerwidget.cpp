#include "centerwidget.h"
#include <mainwindow.h>
#include <QStatusBar>
#include <QPainter>
CenterWidget::CenterWidget(QWidget *parent) :
    QWidget(parent)
{
    pixmap.load("flower.jpg");
    setMinimumSize(400,400);
    drawType=0;
    mouseClickInfo=tr("");
    mousePosInfo=tr("");
    mousePosLabel=new QLabel;
    mousePosLabel->setText(""); //初始显示内容为空
    mousePosLabel->setFixedWidth(100); //控件设置为固定大小
    MainWindow *p=(MainWindow *)parent;
    p->statusBar()->addPermanentWidget (mousePosLabel);
    setMouseTracking(true);
}
void CenterWidget::paintEvent(QPaintEvent *){
    QPainter p(this);
//    p.drawPixmap(600,50,pixmap);
//    QFont font(tr("宋体"),18,QFont::Bold,true);
//    p.setFont(font);
//    p.setPen(QPen(QColor(125,56,0)));
//    p.drawText(QRect(50,50,300,100),Qt::AlignCenter,tr("欢迎进入QT可视化编程的世界！"));
//    QRect rect(200,200,300,200);
//    QPen pen(Qt::red,2,Qt::SolidLine);
//    p.setPen(pen);
//    QBrush brush(Qt::blue);
//    p.setBrush(brush);
//    p.drawEllipse(rect);
    QPen pen(Qt::red,2,Qt::SolidLine);
    p.setPen(pen);
    QPoint p1(50,50),p2(500,300);
    switch(drawType){
    case 0:
        p.drawLine(p1,p2); break;
    case 1:
        p.drawEllipse(QRect(p1,p2)); break;
    case 2:
        p.drawRect(QRect(p1,p2)); break;
    }
    p.drawText(550,200,mouseClickInfo);
    p.drawText(550,300,mousePosInfo);
}
void CenterWidget::setDrawType(int type){
    drawType=type;
}
void CenterWidget::mousePressEvent(QMouseEvent *e){
    mouseClickInfo=tr("Mouse Click at: ")+QString::number(e->x())
            +","+QString::number(e->y());
    update();
}
void CenterWidget::mouseMoveEvent(QMouseEvent *e){
    mousePosInfo=tr("Mouse pos: ")+QString::number(e->x())
            +","+QString::number(e->y());
    mousePosLabel->setText(mousePosInfo); //直接更新状态栏中的控件
    update();
}
