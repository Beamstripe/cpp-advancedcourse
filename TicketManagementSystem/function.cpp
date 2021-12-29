#include "function.h"
#include <sstream>
Time_t getTime(int year, int month, int day, int hour, int minute){
    return Time_t(year,month,day,hour,minute);
}
string outputTime(Time_t t){
    stringstream ss;
    ss<<t.year<<'-'<<t.month<<'-'<<t.day<<' '<<t.hr<<':'<<t.min;
    return ss.str();
}

char modifyMenu(Ticket* p){
    string s;
    int dpy,dpmon,dpd,dph,dpmin,durh,durm;
    double price;
    Time_t t;
    puts("请输入您想修改的选项：");
    puts("1-车次");
    puts("2-出发时间");
    puts("3-票价");
    puts("4-行车时间");
    char c;
    cin>>c;
    switch(c){
    case '1':
        cout<<"输入车次：";
        fflush(stdin);
        getline(cin,s);
        p->setTrainNum(s);
        break;
    case '2':
        cout<<"输入出发时间(年，月，日，小时(24时制)，分钟)：";
        cin>>dpy>>dpmon>>dpd>>dph>>dpmin;
        t=getTime(dpy,dpmon,dpd,dph,dpmin);
        p->setDepartureTime(t);
        break;
    case '3':
        cout<<"输入票价：";
        cin>>price;
        p->setPrice(price);
        break;
    case '4':
        cout<<"输入行车时间：(小时:分钟)";
        scanf("%d:%d",&durh,&durm);
        p->setDepartureTime(durh*60+durm);
        break;
    }
}
string outputTime(int t){
    stringstream ss;
    ss<<(t/60)<<":"<<(t%60);
    return ss.str();
}
char menu(){
    cout<<"--------------欢迎使用车票管理系统---------------"<<endl;
    cout<<"请选择操作："<<endl;
    cout<<"  0-退出系统"<<endl;
    cout<<"  1-添加车票"<<endl;
    cout<<"  2-删除车票"<<endl;
    cout<<"  3-修改车票信息"<<endl;
    cout<<"  4-查找车票"<<endl;
    cout<<"  5-查看所有车票"<<endl;
    cout<<"  6-计算车票总价"<<endl;
    char c;
    cin>>c;
    return c;
}
