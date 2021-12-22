#include <QCoreApplication>
#include <iostream>
#include "header.h"

using namespace std;
//void doAddCommodity(CommodityManage& cm){
//    string name;
//    double price,discount;
//    double tariff;
//    int num,type;
//    cout<<"选择商品类型(0-普通商品， 1-海外购商品)";
//    cin>>type;
//    fflush(stdin);
//    cout<<"输入商品名称:";
//    getline(cin,name);
//    cout<<"输入价格和商品数量:";
//    cin>>price>>num;
//    if(type==0){
//        cout<<"输入商品折扣:";
//        cin>>discount;
//        cm.addCommodity(new
//                        NormalCommodity(name,price,num,discount));
//    }
//    else if(type==1){
//        cout<<"输入商品折扣和关税:";
//        cin>>discount>>tariff;
//        cm.addCommodity(new
//                        OverseaCommodity(name,price,num,discount,tariff));
//    }
//}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"欢迎使用购物篮管理系统!\n";
    char choice;
    CommodityManage cm;
    cm.readData("d:\\commodity04.data");
    while(true){
        choice=menu();
        if(choice=='0')
            break;
        switch(choice){
        case '1':
            doAddCommodity(cm);
            break;
        case '2':
            doRemoveCommodity(cm);
            break;
        case '3':
            doViewCommodity(cm);
            break;
        case '4':
            doViewAllCommodity(cm);
            break;
        case '5':
            doCheckout(cm);
            break;
        default:
            cout<<"无效输入! 请重试!\n";
            break;
        }
    }
    cout<<"再见!\n";
    cm.saveData("d:\\commodity04.data");
    return a.exec();
}
