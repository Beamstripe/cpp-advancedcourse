#include <cmath>
#include <iostream>
using namespace std;
double sqrtIt(double a, double b) {
	if( (a-b) < 0 )
		throw "Sqrt negative number!\n";
	return sqrt( a-b );
}
double divide(double a, double b) {
	if(b==0)
		throw 0;
	return a/b;
}
int main( ) {
	double a, b;
	cout<<"Enter a and b: ";
	cin>>a>>b;
	try {
		cout<<"The Sqrt of a-b: "<<sqrtIt(a, b)<<endl;
		cout<<"a/b: "<<divide(a,b)<<endl;
	} catch(const char * pError) {
		cout<<pError<<endl;
	}
	catch ( int error) {
		cout<<"divided by zero!"<<endl;
	}
	return 0;
}
//Test 1:
/*Enter a and b: 12 0
The Sqrt of a-b: 3.4641
a/b: divided by zero!*/
//Test 2:
/*Enter a and b: 1 10
The Sqrt of a-b: Sqrt negative number!*/
//Test 3:
/*Enter a and b: 127 23
The Sqrt of a-b: 10.198
a/b: 5.52174*/
