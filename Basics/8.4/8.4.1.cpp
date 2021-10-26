#include <iostream>
using namespace std;
class CException {
	public:
		virtual void display() {
			cout<<"Array visit invalid!\n";
		}
};
class CUpperBoundException : public CException {
	public:
		void display() {
			cout<<"Error:index out of bounds!(exceed)"<<endl;
		}
};
class CLowerBoundException : public CException {
	public:
		void display() {
			cout<<"Error:index out of bounds!(below)"<<endl;
		}
};
#define N 3
int getElement(int *p,int index) {
	if(index>=N) throw CUpperBoundException();
	if(index<0) throw CLowerBoundException();
	return p[index];
}
int main() {
	int a[N]= {1,2,3};
	try {
		cout<<getElement(a,2)<<endl;
		cout<<getElement(a,-1)<<endl;
	} catch (CException & ex) {
		ex.display();
	}
	try {
		cout<<getElement(a,4)<<endl;
	} catch(CException & ex) {
		ex.display();
	}
	return 0;
}
//output:
/*3
Error:index out of bounds!(below)
Error:index out of bounds!(exceed)*/
