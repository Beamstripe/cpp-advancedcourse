#include <iostream>
#include <sstream>
#include "SecondhandCommodity.h"
using namespace std;
int SecondhandCommodity::getType()const{
    return 2; //2 表示二手商品
}
string SecondhandCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<discount<<" "<<newnessRate<<endl; //输出子类信息
    return ostr.str();
}
SecondhandCommodity::SecondhandCommodity(long id,std::string name,
                                   double p,int n,double d,double nr)
    :Commodity(id,name,p,n),discount(d),newnessRate(nr){}
SecondhandCommodity::SecondhandCommodity(std::string name,double p,
                                   int n,double d,double nr)
    :Commodity(name,p,n),discount(d),newnessRate(nr){}
double SecondhandCommodity::getNetPrice()const{
    return Commodity::getNetPrice()*discount*newnessRate;
}
void SecondhandCommodity::output()const{
    Commodity::output();
    cout<<" 商品总价:"<<getNetPrice()<<" (价格:"
       <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
      <<discount<<", 成新率:"<<newnessRate<<" )\n";
}
void SecondhandCommodity::modify(){
    string newName;
    int newNum;
    double newPrice,newDiscount,newNewnessRate;
    cout<<"请输入待修改商品的名称：";
    fflush(stdin);
    getline(cin,newName);
    cout<<"请输入待修改商品的价格，数量，折扣与成新率：";
    cin>>newPrice>>newNum>>newDiscount>>newNewnessRate;
    setName(newName);
    setPrice(newPrice);
    setNum(newNum);
    this->discount=newDiscount;
    this->newnessRate=newNewnessRate;
}
