#include <iostream>
#include <string>
#include <functional>
using namespace std;
template<typename T1, typename T2>
T1 cal(T1 a, T1 b, T2 f) {
	return f(a,b);
}
int main() {
	int a=3,b=5;
	cout<<"First:"<<cal(a,b,plus<int>())<<endl;
	cout<<"Second:"<<cal(a,b,minus<int>())<<endl;
	string s1 {"hello"};
	string s2 {"world"};
	cout<<"Third:"<<cal(s1,s2,plus<string>())<<endl;
	return 0;
}
//output:
/*First:8
Second:-2
Third:helloworld*/
