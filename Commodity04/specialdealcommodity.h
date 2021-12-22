#ifndef SPECIALDEALCOMMODITY_H
#define SPECIALDEALCOMMODITY_H
#include "header.h"
class SpecialDealCommodity : public Commodity
{
public:
    virtual ~SpecialDealCommodity(){}
    SpecialDealCommodity(long id,std::string name,
                     double p=0,int n=0,double d=0);
    SpecialDealCommodity(std::string name,double p=0,
                     int n=0,double d=0);
    void setDiscountedPrice(double discountedPrice){this->discountedPrice=discountedPrice;}
    double getDiscountedPrice()const{return discountedPrice;}
    double getOriginalPrice()const{return price;}
    double getPrice()const;
    virtual double getNetPrice()const;
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
private:
    double discountedPrice;
};

#endif // SPECIALDEALCOMMODITY_H
