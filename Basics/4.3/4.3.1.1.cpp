#include <iostream>
#include <cmath>
using namespace std;
class Complex {
	public:
		Complex();
		Complex(double r);
		Complex(double r, double i);
		Complex(const Complex& c);
		~Complex();
		void setValue(double r, double i);
		double getReal() const ;
		double getImage() const;
		double getDistance() const;
		void output() const;
		Complex operator+(const Complex& f)const;
		Complex operator*(const Complex& f)const;
		Complex & operator+=(const Complex & f);
		Complex & operator*=(const Complex & f);
		Complex & operator ++(); 
		Complex operator++(int); 
		Complex add(const Complex& c)const;
		Complex multiply(const Complex& c)const;
		friend Complex operator-(const Complex& f1,const Complex& f2);
		friend std::ostream& operator<<(std::ostream& out,const Complex& f);
		Complex& operator-=(const Complex &f);
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
Complex::Complex(const Complex& c){
	setValue(c.getReal(),c.getImage());
}
Complex::~Complex(){}
Complex Complex::operator+(const Complex& c)const{
	Complex ans;
	ans.setValue(c.getReal()+real,c.getImage()+image);
	return ans;
}
Complex Complex::operator*(const Complex& c)const{
	Complex ans;
	ans.setValue(c.getReal()*real-c.getImage()*image,c.getReal()*image+c.getImage()*real);
	return ans;
}
Complex& Complex::operator+=(const Complex& f){
	setValue(real+f.getReal(),image+f.getImage());
	return *this;
}
Complex& Complex::operator*=(const Complex& f){
	setValue(f.getReal()*real-f.getImage()*image,f.getReal()*image+f.getImage()*real);
	return *this;
}
Complex& Complex::operator++(){
	setValue(real+1,image);
//	cout<<"1"<<endl;//"post" operator
	return *this;
}
Complex Complex::operator++(int){
	Complex ans(*this);
	setValue(real+1,image);
//	cout<<"2"<<endl;//"pred" operator
	return ans;
}
Complex operator-(const Complex& f1,const Complex& f2){
	Complex ans;
	ans.setValue(f1.real-f2.real,f1.image-f2.image);
	return ans;
}
ostream& operator<<(ostream& out,const Complex& f){
	if(fabs(f.real)<0.00001) {
		if(fabs(f.image)<0.00001)
			out<<0<<endl;
		else
			out<<f.image<<'i'<<endl;
	} else {
		if(fabs(f.image)<0.00001) {
			out<<f.real<<endl;
		} else if(f.image>0) {
			out<<f.real<<'+'<<f.image<<'i'<<endl;
		} else {
			out<<f.real<<f.image<<'i'<<endl;
		}
	}
	return out;
}
Complex& Complex::operator-=(const Complex& f){
	setValue(real-f.getReal(),image-f.getImage());
	return *this;
}
int main() {
	Complex a(1,1),b(-1,1),c(0,1);
	c=a*b;
//	b++;
//	++a;
	b.output();
	cout<<c;

	return 0;
}
