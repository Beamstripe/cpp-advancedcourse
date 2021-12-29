#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H

#include<QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include "paintlabel.h"
class MainWindow;
class LeftWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LeftWidget(QWidget *parent = 0);

signals:

public slots:
    void addBall();
    void stopBall();
private:
    QLabel *xLabel,*yLabel,*radiusLabel,*speedLabel,*angleLabel,*colorLabel;
    QLineEdit *xEdit,*yEdit,*radiusEdit,*speedEdit,*angleEdit;
    PaintLabel *colorPreview;
    QPushButton *addButton,*stopButton;
    MainWindow *pmain;
};

#endif // LEFTWIDGET_H
