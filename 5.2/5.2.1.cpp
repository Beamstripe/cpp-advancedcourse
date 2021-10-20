#include <iostream>
#include<cmath>
using namespace std;
class Point {
	public:
		Point( double newX=0, double newY=0);
		Point(const Point& p);
		~Point();
		void setValue(double newX, double newY);
		double getX( ) const;
		double getY() const;
		double getDistance( const Point& p2) const;
	protected:
		double x, y;
};
class Point3D : public Point {
	public:
		Point3D(double newX=0, double newY=0, double newZ=0);
		Point3D(const Point& p);
		double getZ() const;
		double getX( ) const;
		double getY() const;
		double getDistance( const Point3D& p)const;
	private:
		double z;
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
Point3D::Point3D(double newX, double newY, double newZ):z(newZ) {
	setValue(newX,newY);
}
Point3D::Point3D(const Point& p){
	Point::setValue(p.getX(),p.getY());
	z=0;
}
double Point3D::getZ()const {
	return z;
}
double Point3D::getDistance(const Point3D& p) const {
	return sqrt((p.Point::getX()-Point::getX())*(p.Point::getX()-Point::getX())+(p.Point::getY()-Point::getY())*(p.Point::getY()-Point::getY())+(p.getZ()-getZ())*(p.getZ()-getZ()));
}
/*int main() {
	Point p1(3, 4), p2(5,3);
	Point3D p1_3D(3,4,6);
	Point3D p2_3D(2,6,9);
	double dis=p1.getDistance(p2); //????? p1 ? p2 ???
	cout<<"Distance between p1 and p2: "<<dis<<endl;
	dis=p1_3D.getDistance(p2_3D); //?? 3 ?? p1_3D ? p2_3D ???
	cout<<"Distance between p1_3D and p2_3D: "<<dis<<endl;
	return 0;
}*/
//output:
/*Distance between p1 and p2: 2.23607
Distance between p1_3D and p2_3D: 3.74166*/
/*int main() {
	Point p1(3, 4), p2(5,3);
	Point3D p1_3D(3,4,6);
	Point3D p2_3D(2,6,9);
	double dis=p1.getDistance(p2); //????? p1 ? p2 ???
	cout<<"Distance between p1 and p2: "<<dis<<endl;
	dis=p1.getDistance(p2_3D); //?? p1 ? p2_3D ???
	cout<<"Distance between p1 and p2_3D: "<<dis<<endl;
	return 0;
}*/
//output:
/*Distance between p1 and p2: 2.23607
Distance between p1 and p2_3D: 2.23607*/
int main() {
	Point p1(3, 4), p2(5,3);
	Point3D p1_3D(3,4,6);
	Point3D p2_3D(2,6,9);
	double dis=p1.getDistance(p2); //????? p1 ? p2 ???
	cout<<"Distance between p1 and p2: "<<dis<<endl;
	dis=p1.getDistance(p2_3D); //?? p1 ? p2_3D ???
	cout<<"Distance between p1 and p2_3D: "<<dis<<endl;
	dis=p1_3D.getDistance(p2); //??? p1_3D ? p2 ???
	cout<<"Distance between p1_3D and p2: "<<dis<<endl;
	return 0;
}
//Reason:The father objective cannot be converted into child objective(Invalid Parameter)
//output after adding constructor:
/*Distance between p1 and p2: 2.23607
Distance between p1 and p2_3D: 2.23607
Distance between p1_3D and p2: 6.40312*/
