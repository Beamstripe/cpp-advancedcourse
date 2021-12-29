#ifndef PAINTLABEL_H
#define PAINTLABEL_H

#include<QLabel>
#include<QColor>
#include<QMouseEvent>

class PaintLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PaintLabel(QWidget *parent = 0);
    void paintEvent(QPaintEvent* event);
    void setFillColor(QColor color);
    void mousePressEvent(QMouseEvent* e);
    QColor getFillColor();
private:
    QColor fillColor;

signals:

public slots:

};

#endif // PAINTLABEL_H
