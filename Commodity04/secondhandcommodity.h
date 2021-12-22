#ifndef SECONDHANDCOMMODITY_H
#define SECONDHANDCOMMODITY_H
#include "header.h"
class SecondhandCommodity : public Commodity{
public:
    virtual ~SecondhandCommodity();
    SecondhandCommodity();
    SecondhandCommodity(long id,std::string name,
                     double p=0,int n=0,double d=1.0,double nr=1.0);
    SecondhandCommodity(std::string name,double p=0,
                     int n=0,double d=1.0,double nr=1.0);
    void setDiscount(double discount){this->discount=discount;}
    void setNewnessRate(double newnessRate){this->newnessRate=newnessRate;}
    double getDiscount()const{return discount;}
    double getNewnessRate()const{return newnessRate;}
    virtual double getNetPrice()const;
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
private:
    double discount;
    double newnessRate;
};

#endif // SECONDHANDCOMMODITY_H
