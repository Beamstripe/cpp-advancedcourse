#include <iostream>
#include <cmath>
using namespace std;
class Complex {
	public:
		Complex(); //Constructor
		Complex(double r); //Constructor with 1 parameter: Real part
		Complex(double r, double i); //Constructor with 2 parameter: Real Part and Imaginary Part
		void setValue(double r, double i); //set real and imaginary part
		double getReal(); //get real part
		double getImage(); //get img part
		double getDistance(); //get value(distance to original)
		void output(); //Complex Format output
	private:
		double real; //real part
		double image; //img part
};
Complex::Complex():real(0),image(0) {}
Complex::Complex(double r):real(r),image(0) {}
Complex::Complex(double r,double i):real(r),image(i) {}
void Complex::setValue(double r,double i) {
	real=r;
	image=i;
}
double Complex::getReal() {
	return real;
}
double Complex::getImage() {
	return image;
}
double Complex::getDistance() {
	return sqrt(real*real+image*image);
}
void Complex::output() {
	if(fabs(real)<0.00001) {
		if(fabs(image)<0.00001)
			cout<<0<<endl;
		else
			cout<<image<<'i'<<endl;
	} else {
		if(fabs(image)<0.00001) {
			cout<<real<<endl;
		} else if(image>0) {
			cout<<real<<'+'<<image<<'i'<<endl;
		} else {
			cout<<real<<image<<'i'<<endl;
		}
	}
}
int main() {
	Complex c1, c2(2), c3(3,4);
	c1.output();
	c2.output();
	c3.output();
	c1.setValue(6, 4);
	c1.output();
	cout<<c1.getDistance( )<<endl;
	return 0;
}
