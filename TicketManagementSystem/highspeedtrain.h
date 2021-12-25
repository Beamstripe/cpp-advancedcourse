#ifndef HIGHSPEEDTRAIN_H
#define HIGHSPEEDTRAIN_H
#include "train.h"
class HighspeedTrain:public Train
{
public:
    //constructor
    HighspeedTrain()=delete;
    HighspeedTrain(time_t dt,int d,string num,string dept,string dest,bool smart,bool slient);
    //setter
    void setIfSmartCarriage(bool ifSmartCarriage){this->ifSmartCarriage=ifSmartCarriage;}
    void setIfSilientCarriage(bool ifSilientCarriage){this->ifSilientCarriage=ifSilientCarriage;}
    //getter
    bool getIfSmartCarriage(){return ifSmartCarriage;}
    bool getIfSilentCarriage(){return ifSilientCarriage;}
    //virtual
    virtual getPrice()const;
    virtual getTrainType()const;
private:
    bool ifSmartCarriage;
    bool ifSilientCarriage;
};

#endif // HIGHSPEEDTRAIN_H
