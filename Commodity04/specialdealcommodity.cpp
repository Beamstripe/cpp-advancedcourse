#include "specialdealcommodity.h"
#include "header.h"
using namespace std;
int SpecialDealCommodity::getType()const{
    return 3; //3 表示特价商品
}
std::string SpecialDealCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<discountedPrice<<endl; //输出子类信息
    return ostr.str();
}
SpecialDealCommodity::SpecialDealCommodity(long id,std::string name,
                                   double p,int n,double d)
    :Commodity(id,name,p,n),discountedPrice(d){}
SpecialDealCommodity::SpecialDealCommodity(std::string name,double p,
                                   int n,double d)
    :Commodity(name,p,n),discountedPrice(d){}
double SpecialDealCommodity::getNetPrice()const{
    return getNum()*discountedPrice;
}
double SpecialDealCommodity::getPrice()const{
    return discountedPrice;
}

void SpecialDealCommodity::output()const{
    Commodity::output();
    cout<<" 商品原价:"<<price<<"，现价:"
       <<discountedPrice<<", 数量:"<<getNum()<<"，商品总价:"
      <<getNetPrice()<<" \n";
}
