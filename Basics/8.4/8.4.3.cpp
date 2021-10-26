#include <iostream>
using namespace std;
int f(int n) {
	if(n<=0)
		throw n;
	int s=1;
	for(int i=1; i<=n; ++i)
		s*=i;
	return s;
}
int main() {
	try {
		cout<<f(4)<<endl;
		cout<<f(-2)<<endl;
	} catch(int n) {
		cout<<"n="<<n<<"n! invaild."<<endl;
		cout<<"End of program"<<endl;
	}
	return 0;
}
//output:
/*24
n=-2n! invaild.
End of program*/
