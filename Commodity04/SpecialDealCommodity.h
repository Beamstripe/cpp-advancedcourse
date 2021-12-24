#ifndef SPECIALDEALCOMMODITY_H
#define SPECIALDEALCOMMODITY_H
#include <string>
#include <sstream>
#include "Commodity.h"
class SpecialDealCommodity : public Commodity{
public:
    virtual ~SpecialDealCommodity(){}
    SpecialDealCommodity(long id,std::string name,
                     double p=0,int n=0,double pp=0);
    SpecialDealCommodity(std::string name,double p=0,
                     int n=0,double pp=0);
    void setPromotionPrice(double promotionPrice){this->promotionPrice=promotionPrice;}
    double getPromotionPrice()const{return promotionPrice;}
    virtual double getNetPrice()const;
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
    virtual void modify();
private:
    double promotionPrice;
};
#endif // SPECIALDEALCOMMODITY_H
