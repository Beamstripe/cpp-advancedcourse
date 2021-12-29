#ifndef SLEEPERTRAIN_H
#define SLEEPERTRAIN_H
#include "train.h"
class SleeperTrain:public Train
{
public:
    //constructor
    SleeperTrain()=delete;
    SleeperTrain(Time_t dt,int d,string num,string dept,string dest,string pos);
    //setter
    void setSleeperPosition(string sleeperPosition){this->sleeperPosition=sleeperPosition;}
    //getter
    string getSleeperPosition(){return sleeperPosition;}
    //virtual
    virtual string getTrainType()const;
    virtual void output() const;

private:
    string sleeperPosition;
};

#endif // SLEEPERTRAIN_H
