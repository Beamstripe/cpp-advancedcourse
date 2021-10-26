#include <iostream>
#include <cmath>
using namespace std;
class Complex {
	public:
		Complex();
		Complex(double r);
		Complex(double r, double i);
		void setValue(double r, double i);
		double getReal() const ;
		double getImage() const;
		double getDistance() const;
		void output() const;
		Complex add(const Complex& c)const;
		Complex multiply(const Complex& c)const;
	private:
		double real;
		double image;
};
Complex::Complex():real(0),image(0) {}
Complex::Complex(double r):real(r),image(0) {}
Complex::Complex(double r,double i):real(r),image(i) {}
void Complex::setValue(double r,double i) {
	real=r;
	image=i;
}
double Complex::getReal() const {
	return real;
}
double Complex::getImage() const {
	return image;
}
double Complex::getDistance() const {
	return sqrt(real*real+image*image);
}
void Complex::output() const{
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
Complex Complex::multiply(const Complex& c)const{
	Complex ans;
	ans.setValue(c.getReal()*real-c.getImage()*image,c.getReal()*image+c.getImage()*real);
	return ans;
}
Complex Complex::add(const Complex& c)const{
	Complex ans;
	ans.setValue(c.getReal()+real,c.getImage()+image);
	return ans;
}
int main(){
	Complex a(1,2);
	Complex b(-1,-1);
	a.multiply(b).output();
	b.add(a).output();
	return 0;
}
