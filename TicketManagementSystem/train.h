#ifndef TRAIN_H
#define TRAIN_H
#include <ctime>
#include <string>
struct Time_t{
    int year,month,day,hr,min;
    Time_t(int y=0,int mt=0,int d=0,int h=0,int mn=0):year(y),month(mt),day(d),hr(h),min(mn){}
    Time_t getDis(int m){
        if(m/60+hr>23){
            ++day;
            hr=hr-24+m/60;
        }
        if(m/60+min>=60){
            ++hr;
            m=m%60-60+min;
        }
    }
};

using namespace std;
class Train
{
public:
    //constructor
    Train()=default;
    Train(Time_t dt,int d,string num,string dept,string dest);
    //setter
    void setDepartureTime(Time_t departureTime){this->departureTime=departureTime;}
    void setDuration(int duration){this->duration=duration;}
    void setTrainNum(string trainNum){this->trainNum=trainNum;}
    void setDeparture(string departure){this->departure=departure;}
    void setDestination(string destination){this->destination=destination;}
    //getter
    Time_t getDepartureTime()const{return departureTime;}
    int getDuration()const{return duration;}
    string getTrainNum()const{return trainNum;}
    string getDeparture()const{return departure;}
    string getDestination()const{return destination;}
    //virtual
    virtual string getTrainType()const=0;
    virtual void output()const=0;
    //others
    Time_t getArrivalTime()const;
private:
    Time_t departureTime;
    int duration;
    string trainNum;
    string departure;
    string destination;
};

#endif // TRAIN_H
