#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>
#include "ball.h"
#include <QList>
#include <QMouseEvent>
class rightwidget : public QWidget
{
    Q_OBJECT
public:
    explicit rightwidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent*);
    void updateBalls();
    void addBall(const Ball& b);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void setPre(double x,double y){
        prex=x;
        prey=y;
    }

private:
    QList<Ball> balls;
    double prex,prey;
    double x,y;
signals:

public slots:

};

#endif // RIGHTWIDGET_H
