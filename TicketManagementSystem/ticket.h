#ifndef TICKET_H
#define TICKET_H
#include <string>
#include <ctime>
#include "train.h"
#include "standardtrain.h"
#include "sleepertrain.h"
#include "highspeedtrain.h"
#include "seat.h"
using namespace std;

class Ticket
{
public:
    //constructor
    Ticket()=default;
    Ticket(long i,StandardTrain* t, string n,double p,Seat* s);
    Ticket(StandardTrain* t, string n,double p,Seat* s);
    Ticket(long i,SleeperTrain* t, string n,double p,Seat* s);
    Ticket(SleeperTrain* t, string n,double p,Seat* s);
    Ticket(long i,HighspeedTrain* t, string n,double p,Seat* s);
    Ticket(HighspeedTrain* t, string n,double p,Seat* s);
    //setter
    static void setNextId(long id){nextId=id;}
    void setId(long id){this->id=id;}
    void setName(string name){this->name=name;}
    void setPrice(double price){this->price=price;}
    void setTrainNum(string s){this->train->setTrainNum(s);}
    void setDepartureTime(Time_t t){this->train->setDepartureTime(t);}
    void setDuration(int t){this->train->setDuration(t);}
    //getter
    static long getNextId(){return nextId;}
    long getId(){return id;}
    double getPrice(){return price;}
    string getName(){return name;}
    //others
    void output()const;
private:
    double price;
    long id;
    static long nextId;
    string name;
    Train* train;
    Seat* seat;
    long autoNextId(){return nextId++;}
};

#endif // TICKET_H
