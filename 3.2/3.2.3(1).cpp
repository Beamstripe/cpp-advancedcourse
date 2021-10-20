#include <iostream>
#include <iomanip>
#include "MyTime.h"
using namespace std;
Time::Time():hour(0),minute(0) {}
Time::Time(int h,int m) {
	setTime(h,m);
}
Time::Time(int minutes) {
	hour=minutes/60;
	minute=minutes%60;
}
void Time::setTime(int h,int m) {
	hour=h+m/60;
	minute=m%60;
}
void Time::output()const {
	cout<<setfill('0')<<setw(2)<<hour<<':'<<setw(2)<<minute<<endl;
}
int Time::getHour()const {
	return hour;
}
int Time::getMinute()const {
	return minute;
}
int Time::getTotalMinutes()const {
	return hour*60+minute;
}
Time Time::getTimeSpan(const Time &t)const {
	int a=getTotalMinutes();
	int b=t.getTotalMinutes();
	Time ans((a-b>0)?(a-b):(b-a));
	return ans;
}
int main() {
	Time t1(9,20),t2(11,35),t3;
	t3=t1.getTimeSpan(t2);
	t3.output();
	return 0;
}
