#include "ball.h"
#include <cmath>
#include <QPen>
#include <QBrush>
Ball::Ball():Ball(40,100,10,10,45,Qt::red)
{ //通过委托构造实现缺省构造函数
}
Ball::Ball(double xpos,double ypos,double r,double s,double a,QColor c)
    :x(xpos),y(ypos),radius(r),speed(s),angle(a),color(c)
{ }
void Ball::draw(QPainter *p)
{
    QPen pen(color,1,Qt::SolidLine);
    QBrush brush(color);
    p->setPen(pen);
    p->setBrush(brush);
    QRect r(x-radius,y-radius,radius*2,radius*2);
    p->drawEllipse(r);
}
void Ball::move(){
    double dx,dy;
    const double PI=3.14159;
    dx=speed*std::sin(angle*PI/180);
    dy=speed*std::cos(angle*PI/180);
    x+=dx;
    y+=dy;
    setSpeed(speed*0.99);
    if(speed<0.1)setSpeed(0);
    checkBoundary();
}
void Ball::checkBoundary(){
    if(y+radius>rect.height()){
        angle=180-angle;
        y=rect.height()-radius;
    }
    if(y-radius<0){
        angle=180-angle;
        y=radius;
    }
    if(x+radius>rect.width()){
        angle=-angle;
        x=rect.width()-radius;
    }
    if(x-radius<0){
        angle=-angle;
        x=radius;
    }
}
void Ball::checkCollision(Ball &b){
    double dx,dy;
    dx=x-b.x;
    dy=y-b.y;
    double midx=(x+b.x)/2,midy=(y+b.y)/2;
    double dis=std::sqrt(dx*dx+dy*dy);
    double difx=(std::cos(radius+b.radius)-dx)/2;
    double dify=(std::sin(radius+b.radius)-dy)/2;
//    if(x<b.x){
//        x+=difx;
//        b.x-=difx;
//        y+=dify;
//        b.y-=dify;
//    }else{
//        x-=difx;
//        b.x+=difx;
//        y-=dify;
//        b.y+=dify;
//    }
    if(dis<=radius+b.radius){ //碰撞后只是交换速度和角度
        double temp;
        temp=speed;
        speed=0.95*b.speed;
        b.speed=0.95*temp;
        temp=angle;
        if(fabs(angle-b.angle)<=5)
        angle=b.angle;
        b.angle=temp;
    }
}
