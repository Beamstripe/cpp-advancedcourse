#ifndef FUNCTION_H
#define FUNCTION_H
#include "headers.h"
vector<Ticket>::iterator findTicketById(long id);
time_t getTime(int year,int month,int day,int hour,int minute);
string outputTime(time_t t);
string outputTime(int tm);
#endif // FUNCTION_H
