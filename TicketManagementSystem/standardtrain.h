#ifndef STANDARDTRAIN_H
#define STANDARDTRAIN_H
#include "train.h"
class StandardTrain: public Train
{
public:
    //constructor
    StandardTrain()=delete;
    StandardTrain(time_t dt,int d,string num,string dept,string dest);
    //virtual
    virtual double getPrice()const;
    virtual string getTrainType()const;
};

#endif // STANDARDTRAIN_H
