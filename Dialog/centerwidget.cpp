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
    mousePosLabel->setFixedWidth(200); //控件设置为固定大小
    keyPressInfo=tr("No key is pressed.");
    keyPressLabel=new QLabel;
    keyPressLabel->setFixedWidth(300);
    keyPressLabel->setAlignment(Qt::AlignCenter);
    keyPressLabel->setText(keyPressInfo);
    shapeColor=Qt::black;
    MainWindow *p=(MainWindow *)parent;
    p->statusBar()->addPermanentWidget(mousePosLabel);
    p->statusBar()->addPermanentWidget(keyPressLabel);
    setMouseTracking(true);
}
void CenterWidget::paintEvent(QPaintEvent *){
    QPainter p(this);
    if(ifFilled){
        QBrush brush(shapeColor);
        p.setBrush(brush);
    }else{
        QPen pen(shapeColor,2,Qt::SolidLine);
        p.setPen(pen);
    }

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
    p.drawText(750,200,keyPressInfo);
}
void CenterWidget::setDrawType(int type){
    drawType=type;
}
void CenterWidget::setShapeColor(string s){
    if(s=="green")
        shapeColor=Qt::green;
    else if(s=="black")
        shapeColor=Qt::black;
    else if(s=="yellow")
        shapeColor=Qt::yellow;
}
void CenterWidget::setFilled(bool b){
    ifFilled=b;
}
bool CenterWidget::getFilled(){
    return ifFilled;
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
void CenterWidget::keyPressEvent(QKeyEvent *e){
    keyPressInfo=tr("Key ")+e->text()+tr(" is pressed.");
    keyPressLabel->setText(keyPressInfo);
    update();
}
