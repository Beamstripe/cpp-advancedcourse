#include "paintlabel.h"
#include<QPainter>
#include<QWidget>
#include<QColorDialog>
PaintLabel::PaintLabel(QWidget *parent) :
    QLabel(parent)
{
    fillColor=Qt::blue;
}
void PaintLabel::setFillColor(QColor color)
{
    fillColor=color;
}
QColor PaintLabel::getFillColor()
{
    return fillColor;
}
void PaintLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter p(this);
    QPen pen(fillColor,2,Qt::SolidLine);
    QBrush brush(fillColor);
    p.setPen(pen);
    p.setBrush(brush);
    p.drawRect(0,0,this->width(),this->height());
    //根据 fillColor 填充 Label 控件，实现颜色预览
}
void PaintLabel::mousePressEvent(QMouseEvent *e)
{
    QColor chooseColor=QColorDialog::getColor(fillColor); //返回颜色值
    if(chooseColor.isValid()==true) //如果用户取消，则返回无效颜色值
    {
        fillColor=chooseColor;
        update();
    }
}

