#ifndef MYTIME_H
#define MYTIME_H
#include <iostream>
class Time {
	public:
		Time(); //construct Mytime object(set min and hr to 0)
		Time(int h,int m); //construct Mytime object(set min and hr to m,h) ??
		Time(int minutes);
		void setTime(int h, int m); 
		void output()const; //output time in the format of hh:mm
		int getHour()const; 
		int getMinute()const; 
		int getTotalMinutes()const; //get minite passed from 00:00
		Time getTimeSpan(const Time &t)const;
	private:
		int hour;
		int minute;
		void normalizeTime(); //set hour in 0...23 min in 0...59
};
#endif
