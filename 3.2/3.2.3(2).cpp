#include "MyTime.h"
#include <iostream>
#include <iomanip>
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
class ParkingCard {
	public:
		ParkingCard(double newRate) {
			rate = newRate;
		}
		void setRate(double newRate) {
			rate = newRate;
		}
		double getRate() const {
			return rate;
		}
		void setParkingTime( const Time &time);
		void setLeavingTime( const Time &time );
		double getTotalExpenses() const;
		void output() const;
	private:
		double rate;
		Time parkingTime;
		Time leavingTime;
};
void ParkingCard::setParkingTime(const Time &time) {
	parkingTime = time;
}
void ParkingCard::setLeavingTime(const Time &time) {
	leavingTime = time;
}
double ParkingCard::getTotalExpenses() const {
	const Time ans = parkingTime.getTimeSpan(leavingTime);
	return ((ans.getTotalMinutes())+29)/30*(getRate()/2);
}
void ParkingCard::output()const {
	cout<<"Total Expenses: "<<getTotalExpenses()<<endl;
	cout<<"  Parking Time: ";parkingTime.output();
	cout<<"  Leaving Time: ";leavingTime.output();
	cout<<"  Rate: "<<getRate()<<endl;
}
int main() {
	ParkingCard card(5);
	card.setParkingTime(Time(9, 20)); 
	card.setLeavingTime(Time(11, 35));
	cout<<"Expenses: "<<card.getTotalExpenses()<<endl;
	cout<<"Detailed info:\n";
	card.output();
	return 0;
}
