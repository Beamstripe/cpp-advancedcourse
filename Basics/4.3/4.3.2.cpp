#include <iostream>
#include <iomanip>
using namespace std;

class Time {
	public:
		Time();
		Time(int h,int m);
		Time( int minutes );
		void setTime(int h, int m);
		void output() const;
		friend std::ostream& operator<<( std::ostream& out, const Time& t);
		int getHour() const;
		int getMinute() const;
		int getTotalMinutes() const;
		Time getTimeSpan(const Time &newTime )const;
		Time operator-(const Time& newTime)const;
	private:
		int hour;
		int minute;
		void normalizeTime(); //?????? 0~23,??? 0~59
};
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
/*void Time::output()const {
	cout<<setfill('0')<<setw(2)<<hour<<':'<<setw(2)<<minute<<endl;
}*/
int Time::getHour()const {
	return hour;
}
int Time::getMinute()const {
	return minute;
}
int Time::getTotalMinutes()const {
	return hour*60+minute;
}
/*Time Time::getTimeSpan(const Time &t)const {
	int a=getTotalMinutes();
	int b=t.getTotalMinutes();
	Time ans((a-b>0)?(a-b):(b-a));
	return ans;
}*/
ostream& operator<<(ostream& out,const Time& t) {
	out<<setfill('0')<<setw(2)<<t.hour<<':'<<setw(2)<<t.minute<<endl;
	return out;
}
Time Time::operator-(const Time& newTime)const {
	int a=getTotalMinutes();
	int b=newTime.getTotalMinutes();
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
		friend std::ostream& operator<<( std::ostream& out,const ParkingCard& t);
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
	const Time ans = parkingTime-leavingTime;
	return ((ans.getTotalMinutes())+29)/30*(getRate()/2);
}
/*void ParkingCard::output()const {
	cout<<"Total Expenses: "<<getTotalExpenses()<<endl;
	cout<<"  Parking Time: ";parkingTime.output();
	cout<<"  Leaving Time: ";leavingTime.output();
	cout<<"  Rate: "<<getRate()<<endl;
}*/
ostream& operator<<(ostream& out,const ParkingCard& f) {
	out<<"Total Expenses: "<<f.getTotalExpenses()<<endl;
	out<<"  Parking Time: "<<f.parkingTime;
	out<<"  Leaving Time: "<<f.leavingTime;
	out<<"  Rate: "<<f.rate<<endl;
	return out;
}
int main() {
	ParkingCard card(5);
	card.setParkingTime(Time(9, 20) );
	card.setLeavingTime(Time(11, 35) );
	cout<<"Expenses: "<<card.getTotalExpenses()<<endl;
	cout<<"Detailed info:\n";
	cout<<card<<endl;
	return 0;
}
