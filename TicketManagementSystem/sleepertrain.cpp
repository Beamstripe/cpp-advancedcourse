#include "sleepertrain.h"
#include "function.h"
SleeperTrain::SleeperTrain(Time_t dt, int d, string num, string dept, string dest, string pos){
    setDepartureTime(dt);
    setDuration(d);
    setTrainNum(num);
    setDeparture(dept);
    setDestination(dest);
    setSleeperPosition(pos);
}

void SleeperTrain::output()const{
    cout<<"车次："<<getTrainNum()<<endl;
    cout<<"起止地："<<getDeparture()<<"---"<<getDestination()<<endl;
    cout<<"出发时间："<<outputTime(getDepartureTime())<<endl;
    cout<<"行车时长："<<outputTime(getDuration())<<endl;
//    cout<<"到达时间："<<outputTime(getArrivalTime())<<endl;
}
string SleeperTrain::getTrainType()const{
    return "卧铺列车";
}
