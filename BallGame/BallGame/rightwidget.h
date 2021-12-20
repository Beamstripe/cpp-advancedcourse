#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>
#include "ball.h"
#include <QList>
class rightwidget : public QWidget
{
    Q_OBJECT
public:
    explicit rightwidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent*);
    void updateBalls();
    void addBall(const Ball& b);
private:
    QList<Ball> balls;
signals:

public slots:

};

#endif // RIGHTWIDGET_H
