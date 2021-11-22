#include "dialog.h"
#include <QGridLayout>
#include <signal.h>
#include <qobjectdefs.h>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent){
    radiusLabel=new QLabel(this);
    radiusLabel->setText(tr("Radius:"));
    radiusLineEdit=new QLineEdit(this);
    areaLabel=new QLabel(this);
    calButton=new QPushButton(this);
    calButton->setText(tr("Calculate Area:"));
    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->addWidget(radiusLabel,0,0);
    mainLayout->addWidget(radiusLineEdit,0,1);
    mainLayout->addWidget(areaLabel,1,0);
    mainLayout->addWidget(calButton,1,1);
    setLayout(mainLayout);
    connect(calButton,SIGNAL(clicked()),this,SLOT(showArea()));
    connect(radiusLineEdit,SIGNAL(textChanged(QString)),
        this,SLOT(showArea()));
}
const static double PI=3.14159;
void Dialog::showArea(){
    QString radiusText=radiusLineEdit->text();
    bool ok;
    double radius=radiusText.toDouble(&ok);
    double area=radius*radius*PI;
    QString temp;
    areaLabel->setText(temp.setNum(area));
}
Dialog::~Dialog(){}
