#include <QCoreApplication>
#include <iostream>
#include "header.h"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"欢迎使用购物篮管理系统！\n";
    readData("commmodity2.dat");
    while(true){
        char choice=menu();
        if(choice=='0')
            break;
        switch(choice)  {
        case '1':
            addCommodity(commodities,commodityNum);
            break;
        case '2':
            removeCommodity(commodities,commodityNum);
            break;
        case '3':
            viewCommodity(commodities,commodityNum);
            break;
        case '4':
            displayCommodities(commodities,commodityNum);
            break;
        case '5':
            checkOut(commodities,commodityNum);
            break;
        default:
            cout<<"无效输入！请重试！\n";
            break;
        }
    }
    writeData("commodity2.dat");
    delete[] pCommodities;
    cout<<"再见！\n";
    return a.exec();
}
