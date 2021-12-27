#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <string>
using namespace std;
class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent*);
    void setDrawType(int type);
    void setShapeColor(string s);
    void setFilled(bool b);
    bool getFilled();
signals:

public slots:

private:
    QPixmap pixmap;
    int drawType;
    QLabel *mousePosLabel;
    QString mouseClickInfo;
    QString mousePosInfo;
    QLabel* keyPressLabel;
    QString keyPressInfo;
    QColor shapeColor;
    bool ifFilled;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
};

#endif // CENTERWIDGET_H
