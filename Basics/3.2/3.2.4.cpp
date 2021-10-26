#include <iostream>
#include <cmath>
using namespace std;
class Point {
	public:
		Point( double newX=0, double newY=0);
		Point(const Point& p);
		~Point();
		void setValue(double newX, double newY);
		double getX( ) const;
		double getY() const;
		double getDistance( const Point& p2)const;
		friend double getDistance3(const Point& p1,const Point& p2);
	private:
		double x, y;
};
class Triangle {
	public:
		Triangle(const Point &p1, const Point& p2, const Point& p3);
		double getArea()const;
		double getPerimeter()const;
	private:
		Point p1,p2,p3;
};
Point::Point( double newX, double newY):x(newX),y(newY) {}
Point::Point(const Point& p):x(p.getX()),y(p.getY()) {}
Point::~Point() {}
void Point::setValue(double newX,double newY) {
	x=newX;
	y=newY;
}
double Point::getX()const {
	return x;
}
double Point::getY()const {
	return y;
}
double Point::getDistance(const Point& p2)const {
	return sqrt((x-p2.getX())*(x-p2.getX())+(y-p2.getY())*(y-p2.getY()));
}
double getDistance2(const Point& p1,const Point& p2) {
	return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
}
double getDistance3(const Point& p1,const Point& p2) {
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
Triangle::Triangle(const Point &p1, const Point& p2, const Point& p3) {
	this->p1=p1;
	this->p2=p2;
	this->p3=p3;
}
double Triangle::getArea()const {
	double a=p1.getDistance(p2),b=p2.getDistance(p3),c=p2.getDistance(p3);
	double d=(a+b+c)/2;
	return sqrt(d*(d-a)*(d-b)*(d-c));
}
double Triangle::getPerimeter()const {
	return p1.getDistance(p2)+p2.getDistance(p3)+p3.getDistance(p1);
}
/*int main() {
	Point p1(3,4);
	Point p2(5,2);
	double distance = p1.getDistance(p2);
	double distance2 = getDistance2(p1,p2);
	double distance3 = getDistance3(p1,p2);
//	cout<<"Distance: "<<distance<<endl;
//	cout<<"Distance: "<<distance2<<endl;
	cout<<"Distance: "<<distance3<<endl;
	return 0;
}*/
int main() {
	Point p1(0,0), p2(0,3), p3(4,0);
	Triangle t(p1,p2,p3);
	cout<<"Area: "<<t.getArea()<<endl;
	cout<<"Perimeter: "<<t.getPerimeter()<<endl;
	return 0;
}
