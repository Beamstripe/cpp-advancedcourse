#ifndef FUNCTION_H
#define FUNCTION_H
#include "headers.h"
vector<Ticket>::iterator findTicketById(long id);
time_t getTime(int year,int month,int day,int hour,int minute);
string outputTime(time_t t);
string outputTime(int tm);
enum class optionType:char{
    EXIT='0',ADD='1',REMOVE='2',MODIFY='3',VIEW='4',VIEWALL='5',PRINTCOST='6'
};
optionType menu();
void printTime(time_t t);

#endif // FUNCTION_H
