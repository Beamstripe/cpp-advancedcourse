#include <iostream>
using namespace std;
template<typename T>
T average( T *pd, int n) {
	T sum=0;
	int i=0;
	while(i<n)
		sum+=pd[i++];
	return sum/n;
}
int main() {
	double a[]= {2.5,4.5,6.5,8.5};
	cout<<"Average of a: "<<average(a, 4)<<endl;
	int b[]= {3,5,7,8};
	cout<<"Average of b: "<<average(b, 4)<<endl;
	return 0;
}
//output:
/*Average of a: 5.5
Average of b: 5*/
