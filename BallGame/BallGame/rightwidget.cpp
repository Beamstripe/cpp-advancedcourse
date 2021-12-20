#include "rightwidget.h"
#include <QPainter>
rightwidget::rightwidget(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(400,200);
    balls.clear(); //清空后手工添加 3 个小球，用于测试
    addBall(Ball(30,20,10,10,49,Qt::red));
    addBall(Ball(56,200,10,4,39,Qt::blue));
    addBall(Ball(80,100,10,7,69,Qt::yellow));
}
void rightwidget::paintEvent(QPaintEvent *){
    QPainter p(this);
//    ball.draw(&p);
    for(auto& b:balls)
    b.draw(&p);
}
void rightwidget::updateBalls() //封装的控制小球移动的接口
{
//    ball.setRectangle(this->geometry()); //为小球设置检测的窗口边界
//    ball.move();
    for(auto &b:balls){
        b.setRectangle(this->geometry());
        b.move();
    }
    int i,j;
    for(i=0;i<balls.size()-1;++i){
        for(j=i+1;j<balls.size();++j)
            balls[i].checkCollision(balls[j]);
    }
    update(); //更新窗口显示，重绘小球
}
void rightwidget::addBall(const Ball &b){
    balls.append(b);
}
