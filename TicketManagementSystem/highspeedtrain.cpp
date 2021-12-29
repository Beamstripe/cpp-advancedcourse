#include "highspeedtrain.h"
#include "function.h"

using namespace std;
HighspeedTrain::HighspeedTrain(Time_t dt, int d, string num, string dept, string dest, bool smart, bool silent){
    setDepartureTime(dt);
    setDuration(d);
    setTrainNum(num);
    setDeparture(dept);
    setDestination(dest);
    setIfSilientCarriage(silent);
    setIfSmartCarriage(smart);
}
string HighspeedTrain::getTrainType()const{
    return "高速列车";
}
void HighspeedTrain::output()const{
    cout<<"车次："<<getTrainNum()<<endl;
    if(ifSilientCarriage)cout<<"静音车厢 ";
    if(ifSmartCarriage)cout<<"智能车厢 ";
    cout<<endl;
    cout<<"起止地："<<getDeparture()<<"---"<<getDestination()<<endl;
    cout<<"出发时间："<<outputTime(getDepartureTime())<<endl;
    cout<<"行车时长："<<outputTime(getDuration())<<endl;
}
