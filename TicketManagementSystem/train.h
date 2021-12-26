#ifndef TRAIN_H
#define TRAIN_H
#include <ctime>
#include <string>
#include "seat.h"
using namespace std;
class Train
{
public:
    //constructor
    Train()=delete;
    Train(time_t dt,int d,string num,string dept,string dest);
    //setter
    void setDepartureTime(time_t departureTime){this->departureTime=departureTime;}
    void setDuration(int duration){this->duration=duration;}
    void setTrainNum(string trainNum){this->trainNum=trainNum;}
    void setDeparture(string departure){this->departure=departure;}
    void setDestination(string destination){this->destination=destination;}
    //getter
    time_t getDepartureTime(){return departureTime;}
    int getDuration(){return duration;}
    string getTrainNum(){return trainNum;}
    string getDeparture(){return departure;}
    string getDestination(){return destination;}
    //virtual
    virtual double getPrice()const=0;
    virtual string getTrainType()const=0;
    virtual void output()const=0;
    //others
    time_t getArrivalTime();
private:
    time_t departureTime;
    int duration;
    string trainNum;
    string departure;
    string destination;
    Seat seat;
};

#endif // TRAIN_H
