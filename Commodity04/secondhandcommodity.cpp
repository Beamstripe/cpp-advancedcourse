#include "secondhandcommodity.h"
#include "secondhandcommodity.h"
int SecondhandCommodity::getType()const{
    return 2;//2 表示折旧商品
}
std::string SecondhandCommodity::getInfo()const{
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
      <<discount<<", 折旧程度:"<<newnessRate<<" )\n";
}
