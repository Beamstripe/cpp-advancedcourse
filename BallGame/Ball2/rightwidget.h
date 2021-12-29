#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H
#include "ball.h"
#include <QWidget>
#include <QList>
class RightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void updateBalls();//移动小球的接口
    void addBall(const Ball& b);//添加小球的接口
private:
    //Ball ball;
    QList<Ball> balls;
signals:

public slots:

};

#endif // RIGHTWIDGET_H
