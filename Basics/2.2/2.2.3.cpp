#include <iostream>
#include <iomanip>
#include "MyTime.h"
using namespace std;
Time::Time():hour(0),minute(0) {}
Time::Time(int h,int m) {
	setTime(h,m);
}
void Time::setTime(int h,int m) {
	hour=h+m/60;
	minute=m%60;
}
void Time::output() {
	cout<<setfill('0')<<setw(2)<<hour<<':'<<setw(2)<<minute<<endl;
}
int Time::getHour() {
	return hour;
}
int Time::getMinute() {
	return minute;
}
int Time::getTotalMinutes() {
	return hour*60+minute;
}
int main() {
	Time t1(12, 75);
	t1.output();
	t1.setTime(8, 65);
	t1.output();
	cout<<"t1 Hour: "<<t1.getHour()<<endl;
	cout<<"t1 Minute: "<<t1.getMinute()<<endl;
	cout<<"t1 TotalMinutes: "<<t1.getTotalMinutes()<<endl;
	return 0;
}
