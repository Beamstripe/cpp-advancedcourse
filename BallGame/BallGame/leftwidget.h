#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "paintlabel.h"
class MainWindow;
class leftwidget : public QWidget
{
    Q_OBJECT
public:
    explicit leftwidget(QWidget *parent = 0);
private:
    QLabel *xLabel,*yLabel,*radiusLabel,
    *speedLabel,*angleLabel,*colorLabel;
    QLineEdit *xEdit,*yEdit,*radiusEdit,*speedEdit,*angleEdit;
    QPushButton *addButton,*stopButton;
    MainWindow *pmain; //指向主窗口的指针
    PaintLabel *colorPreview;
signals:

public slots:
    void addBall(); //添加小球
    void stopBall(); //控制定时器的启动与暂停
};

#endif // LEFTWIDGET_H
