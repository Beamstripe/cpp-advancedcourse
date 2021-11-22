#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent*);
    void setDrawType(int type);
signals:

public slots:

private:
    QPixmap pixmap;
    int drawType;
    QLabel *mousePosLabel;
    QString mouseClickInfo;
    QString mousePosInfo;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // CENTERWIDGET_H
