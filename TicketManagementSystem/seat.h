#ifndef SEAT_H
#define SEAT_H
#include <string>
using namespace std;

class Seat
{
public:
    //constructor
    Seat()=delete;
    Seat(int cn,string pos,string c,bool b):carriageNum(cn),position(pos),category(c),ifNoSeat(b){}
    //setter
//    void setGrade(string grade){this->grade=grade;}
    void setCarriageNum(int carriageNum){this->carriageNum=carriageNum;}
    void setPosition(string position){this->position=position;}
    void setCategory(string category){this->category=category;}
    //getter
//    string getGrade(){return grade;}
    int getCarriageNum()const{return carriageNum;}
    string getPosition()const{return position;}
    string getCategory()const{return category;}
    void output()const;
private:
    bool ifNoSeat;
    int carriageNum;
    string position;
    string category;
};

#endif // SEAT_H
