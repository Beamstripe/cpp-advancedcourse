#include "headers.h"
#ifndef FUNCTION_H
#define FUNCTION_H


Time_t getTime(int year,int month,int day,int hour,int minute);
string outputTime(Time_t t);
string outputTime(int t);
//enum class optionType:char{
//    EXIT='0',ADD='1',REMOVE='2',MODIFY='3',VIEW='4',VIEWALL='5',PRINTCOST='6'
//};
char menu();
char modifyMenu(Ticket *p);


#endif // FUNCTION_H
