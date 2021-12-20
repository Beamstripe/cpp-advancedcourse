#ifndef BALL_H
#define BALL_H
#include <QColor>
#include <QRect>
#include <QPainter>
class Ball
{
public:
    Ball();
    Ball(double xpos,double ypos,double r,double s,double a,
         QColor c);
    void setRectangle(const QRect& rect){
        this->rect=rect;
    }
    void draw(QPainter *p); //绘制小球
    void move(); //在指定的方向上移动 1 步
    void checkCollision(Ball &b);
private:
    double x,y; //小球的中心为位置
    double radius; //小球半径
    double speed; //小球移动速度
    double angle; //小球移动角度
    QColor color; //小球填充颜色
    QRect rect; //用于检测的窗口矩形区域
    void checkBoundary();
};

#endif // BALL_H
