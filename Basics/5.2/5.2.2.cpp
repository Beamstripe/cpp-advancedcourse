#include <iostream>
#include <cmath>
using namespace std;
const double PI=3.14;
class Shape {
	public:
		//1
		virtual double getArea()const;
		virtual double getPerimeter()const ;
		//2
//		virtual double getArea()const=0;
//		virtual double getPerimeter()const=0;
};
//1
double Shape::getArea()const {
	return 0;
}
double Shape::getPerimeter()const {
	return 0;
}
class Circle: public Shape {
	public:
		Circle(double r) : radius(r) {}
		double getArea() const;
		double getPerimeter() const;
	private:
		double radius;
};
double Circle::getArea( )const {
	return PI*radius*radius;
}
double Circle::getPerimeter( )const {
	return 2*PI*radius;
}
class Rectangle: public Shape {
	public:
		Rectangle( double w, double h): width(w), height(h) {}
		double getArea()const;
		double getPerimeter()const;
	private:
		double width;
		double height;
};
double Rectangle::getArea()const {
	return width*height;
}
double Rectangle::getPerimeter( )const {
	return 2*(width+height);
}
class Triangle : public Shape {
	public:
		Triangle(double newA, double newB, double newC);
		virtual double getArea( )const;
		virtual double getPerimeter( )const;
	private:
		double a, b, c;
};
Triangle::Triangle(double newA,double newB,double newC):a(newA),b(newB),c(newC){}
double Triangle::getArea()const{
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
double Triangle::getPerimeter()const{
	return a+b+c;
}
int main() {
	Shape *pShapes[3]; //????????
//1-2
	/*pShapes[0]=new Shape;
	pShapes[1]=new Rectangle(3,4);
	pShapes[2]=new Circle(1.0);*/
//3
	pShapes[0]=new Rectangle(3,4);
	pShapes[1]=new Circle(1.0);
//	pShapes[2]=new Rectangle(2,1);
//4
	pShapes[2]=new Triangle(3,4,5);
	double totalArea=0, totalPerimeter=0;
	for(int i=0; i<3; ++i) {
		totalArea+=pShapes[i]->getArea();
		totalPerimeter+=pShapes[i]->getPerimeter();
	}
	cout<<"Total Area: "<<totalArea<<endl;
	cout<<"Total Perimeter: "<<totalPerimeter<<endl;
	for(int i=0; i<3; ++i)
		delete pShapes[i];
	return 0;
}
//----------------------
//output:
/*Total Area: 0
Total Perimeter: 0*/
//reasons:
/*	father functions are deployed instead of childs'
	Because we have created the Shape array instead of Circle and Rectangle
	father functions have greater priority to execute*/
//----------------------
//output after turning father functions into virtual:
/*Total Area: 15.14
Total Perimeter: 20.28*/
//----------------------
//output
/*Total Area: 17.14
Total Perimeter: 26.28*/
//----------------------
//output
/*Total Area: 21.14
Total Perimeter: 32.28*/
