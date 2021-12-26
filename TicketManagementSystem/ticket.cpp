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
    cout<<"ÐÕÃû£º"<<name<<endl;
    train->output();
    seat->output();
}
