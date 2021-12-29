#include "ticket.h"
#include <iostream>
using namespace std;
Ticket::Ticket(long i,StandardTrain* t, string n,double p,Seat* s):id(i),train(t),name(n),price(p),seat(s){}
Ticket::Ticket(StandardTrain* t, string n,double p,Seat* s):id(autoNextId()),train(t),name(n),price(p),seat(s){}
Ticket::Ticket(long i,SleeperTrain* t, string n,double p,Seat* s):id(i),train(t),name(n),price(p),seat(s){}
Ticket::Ticket(SleeperTrain* t, string n,double p,Seat* s):id(autoNextId()),train(t),name(n),price(p),seat(s){}
Ticket::Ticket(long i,HighspeedTrain* t, string n,double p,Seat* s):id(i),train(t),name(n),price(p),seat(s){}
Ticket::Ticket(HighspeedTrain* t, string n,double p,Seat* s):id(autoNextId()),train(t),name(n),price(p),seat(s){}

void Ticket::output()const{
    cout<<"----------------------------------------"<<endl;
    cout<<"编号:"<<id<<endl;
    cout<<"姓名："<<name<<endl;
    cout<<"列车类型："<<train->getTrainType()<<endl;
    train->output();
    seat->output();
}
