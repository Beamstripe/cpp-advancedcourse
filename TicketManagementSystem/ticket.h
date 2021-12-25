#ifndef TICKET_H
#define TICKET_H
#include <string>
#include <ctime>
#include "train.h"
#include "seat.h"
using namespace std;

class Ticket
{
public:
    //constructor
    Ticket()=default;
    Ticket(long id,string name,Train train);
    Ticket(string name,Train train);
    //setter
    static void setNextId(long id){nextId=id;}
    //getter
    static long getNextId(){return nextId;}
    //others
    void output()const;
private:
    double price;
    long id;
    static long nextId;
    long autoNextId(){return nextId++;}
};

#endif // TICKET_H
