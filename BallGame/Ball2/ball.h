#ifndef BALL_H
#define BALL_H
#include<QColor>
#include<QRect>
#include<QPainter>
class Ball
{
public:
    Ball();
    Ball(double xpos,double ypos,double r,double s,double a,QColor c);
    void setRectangle(const QRect& rect)
    {
        this->rect=rect;
    }
    void draw(QPainter *p);
    void move();
    void checkCollision(Ball &b);
private:
    double x,y;
    double radius,speed,angle;
    QColor color;
    QRect rect;
    void checkBoundary();
};

#endif // BALL_H
