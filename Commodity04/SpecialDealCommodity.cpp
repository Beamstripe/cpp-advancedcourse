#include <iostream>
#include "SpecialDealCommodity.h"

using namespace std;
int SpecialDealCommodity::getType()const{
    return 3; //3 表示特价商品
}
string SpecialDealCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<promotionPrice<<endl; //输出子类信息
    return ostr.str();
}
SpecialDealCommodity::SpecialDealCommodity(long id,std::string name,
                                   double p,int n,double pp)
    :Commodity(id,name,p,n),promotionPrice(pp){}
SpecialDealCommodity::SpecialDealCommodity(std::string name,double p,
                                   int n,double pp)
    :Commodity(name,p,n),promotionPrice(pp){}
double SpecialDealCommodity::getNetPrice()const{
    return promotionPrice*getNum();
}
void SpecialDealCommodity::output()const{
    Commodity::output();
    cout<<" 商品总价:"<<getNetPrice()<<" (原价:"
       <<getPrice()<<", 现价:"<<promotionPrice<<", 数量:"<<getNum()<<" )\n";
}
void SpecialDealCommodity::modify(){
    string newName;
    int newNum;
    double newPrice,newPromotionPrice;
    cout<<"请输入待修改商品的名称：";
    fflush(stdin);
    getline(cin,newName);
    cout<<"请输入待修改商品的原价，数量，折扣价：";
    cin>>newPrice>>newNum>>newPromotionPrice;
    setName(newName);
    setPrice(newPrice);
    setNum(newNum);
    this->promotionPrice=newPromotionPrice;
}
