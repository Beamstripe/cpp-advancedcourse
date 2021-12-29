#ifndef STANDARDTRAIN_H
#define STANDARDTRAIN_H
#include "train.h"
class StandardTrain: public Train
{
public:
    //constructor
    StandardTrain()=delete;
    StandardTrain(Time_t dt,int d,string num,string dept,string dest);
    //virtual
    virtual string getTrainType()const;
    virtual void output() const;
};

#endif // STANDARDTRAIN_H
