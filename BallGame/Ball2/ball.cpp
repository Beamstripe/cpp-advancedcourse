#include "ball.h"
#include<cmath>
#include<QPen>
#include<QBrush>
Ball::Ball():Ball(40,100,10,10,45,Qt::red){}
Ball::Ball(double xpos, double ypos, double r, double s, double a, QColor c)
    :x(xpos),y(xpos),radius(r),speed(s),angle(a),color(c)
{
}
void Ball::draw(QPainter *p)
{
    QPen pen(color,1,Qt::SolidLine);
    QBrush brush(color);
    p->setPen(pen);
    p->setBrush(brush);
    QRect r(x-radius,y-radius,radius*2,radius*2);
    p->drawEllipse(r);
}
void Ball::move()
{
    double dx,dy;
    const double PI=3.14159;
    dx=speed*std::sin(angle*PI/180);
    dy=speed*std::cos(angle*PI/180);
    x+=dx;
    y+=dy;
    checkBoundary();
}
void Ball::checkBoundary()
{
    if (y+radius>rect.height())
    {
        angle=180-angle;
        y=rect.height()-radius;
    }
    if (y-radius<0)
    {
        angle=180-angle;
        y=radius;
    }
    if (x+radius>rect.width())
    {
        angle=-angle;
        x=rect.width()-radius;
    }
    if (x-radius<0)
    {
        angle=-angle;
        x=radius;
    }
}

void Ball::checkCollision(Ball &b)
{
    double dx,dy;
    dx=x-b.x;
    dy=y-b.y;
    double dis=std::sqrt(dx*dx+dy*dy);
    if (dis<=radius+b.radius)
    {
        double temp;
        temp=speed;
        speed=b.speed;
        b.speed=temp;
        temp=angle;
        angle=b.angle;
        b.angle=temp;
    }
}
