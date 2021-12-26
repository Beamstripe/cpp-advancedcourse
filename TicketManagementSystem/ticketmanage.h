#ifndef TICKETMANAGE_H
#define TICKETMANAGE_H
#include "function.h"
class TicketManage
{
public:
    TicketManage()=default;
    ~TicketManage();
    void addTicket();
    void modifyTicket();
    void removeTicket();
    void viewTicket();
    void viewAllTickets();
    void printCosts();
private:
    vector<Ticket*> pTickets;
    Ticket* findTicketById(long id);
    const Ticket* findTicketById(long id)const;
    Ticket* findTicketByName(string name);
    const Ticket* findTicketByName(string name)const;
    int maxsize;
    int size;
    vector<Ticket*>::iterator getIterator(Ticket* p);
};
enum trainCategory{
    STANDARD_TRAIN=1,SLEEPER_TRAIN,HIGHSPEED_TRAIN
};

enum expressSeatCategory{
    NO_SEATS,SECONDARY_CLASS,FIRST_CLASS,BUSINESS_CLASS
};
enum normalSeatCategory{
    NO_SEAT,HARD_SEAT,HARD_SLEEPER,SOFT_SLEEPER
};
enum sleeperPositionCategory{
    LOWER_BERTH=1,UPPER_BERTH,MIDDLE_BERTH
};

#endif // TICKETMANAGE_H
