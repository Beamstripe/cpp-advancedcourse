#include "standardtrain.h"
#include "function.h"

StandardTrain::StandardTrain(Time_t dt, int d, string num, string dept, string dest){
    setDepartureTime(dt);
    setDuration(d);
    setTrainNum(num);
    setDeparture(dept);
    setDestination(dest);
}

void StandardTrain::output()const{
    cout<<"起止地："<<getDeparture()<<"---"<<getDestination()<<endl;
    cout<<"出发时间："<<outputTime(getDepartureTime())<<endl;
    cout<<"行车时长："<<outputTime(getDuration())<<endl;
//    cout<<"到达时间："<<outputTime(getArrivalTime())<<endl;
}
string StandardTrain::getTrainType()const{
    return "普速列车";
}
