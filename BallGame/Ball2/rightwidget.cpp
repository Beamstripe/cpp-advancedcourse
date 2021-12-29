#include "rightwidget.h"
#include<QPainter>
RightWidget::RightWidget(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(400,200);
    balls.clear();
    addBall(Ball(30,20,10,10,49,Qt::red));
    addBall(Ball(56,200,10,4,39,Qt::blue));
    addBall(Ball(80,100,10,7,69,Qt::yellow));
    addBall(Ball(12,140,10,5,79,Qt::green));
    addBall(Ball(45,50,10,11,59,Qt::gray));
}
void RightWidget::addBall(const Ball &b)
{
    balls.append(b);
}

void RightWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    //ball.draw(&p);
    for (auto &b:balls)
        b.draw(&p);
}
void RightWidget::updateBalls()
{
    //ball.setRectangle(this->geometry());
    //为小球设置检测的窗口边界
    //ball.move();
    for (auto &b:balls)
    {
        b.setRectangle(this->geometry());
        b.move();
    }
    for (int i=0;i<balls.size()-1;++i)
        for (int j=i+1;j<balls.size();++j)
            balls[i].checkCollision(balls[j]);
    update();
}
