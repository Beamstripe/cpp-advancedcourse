#ifndef COMMODITY_H
#define COMMODITY_H
#include <string>

class Commodity{
public:
    virtual ~Commodity(){}
    Commodity()=default;
    Commodity(long i,std::string n,double p,int nn);
    Commodity(std::string n,double p,int nn);
    virtual int getType()const=0;
    virtual std::string getInfo()const;
    void setPrice(double price){this->price=price;}
    void setNum(int num){this->num=num;}
    void setName(std::string name){this->name=name;}
    std::string getName()const{return name;}
    double getPrice()const{return price;}
    int getNum()const{return num;}
    long getId()const{return id;}
    virtual double getNetPrice()const;
    virtual void output()const;
    static void setNextId(long id){nextId=id;}
    static long getNextId(){return nextId;}
private:
    long id;
    std::string name;
    double price; //商品数量
    int num; //购买数量
    static long nextId;
    long autoNextId(){return nextId++;}
};
#endif // COMMODITY_H
