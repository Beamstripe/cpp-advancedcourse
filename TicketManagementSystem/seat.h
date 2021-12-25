#ifndef SEAT_H
#define SEAT_H
#include <string>
using namespace std;

class Seat
{
public:
    //constructor
    Seat();
    //setter
    void setGrade(string grade){this->grade=grade;}
    void setCarriageNum(int carriageNum){this->carriageNum=carriageNum;}
    void setPosition(string position){this->position=position;}
    void setCategory(string category){this->category=category;}
    //getter
    string getGrade(){return grade;}
    int getCarriageNum(){return carriageNum;}
    string getPosition(){return position;}
    string getCategory(){return category;}
private:
    string grade;
    int carriageNum;
    string position;
    string category;
};

#endif // SEAT_H
