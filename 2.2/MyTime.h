class Time {
	public:
		Time(); //construct Mytime object(set min and hr to 0)
		Time(int h,int m); //construct Mytime object(set min and hr to m,h) ??
		void setTime(int h, int m); 
		void output(); //output time in the format of hh:mm
		int getHour(); 
		int getMinute(); 
		int getTotalMinutes(); //get minite passed from 00:00
	private:
		int hour;
		int minute;
		void normalizeTime(); //set hour in 0...23 min in 0...59
};
