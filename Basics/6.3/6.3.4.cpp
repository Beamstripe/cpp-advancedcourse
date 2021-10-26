#include <iostream>
#include <string>
using namespace std;
template<typename T>
T add(T a, T b) {
	return a+b;
}
template<typename T>
T sub(T a, T b) {
	return a-b;
}
template<typename T1, typename T2>
T1 cal(T1 a, T1 b, T2 f) {
	return f(a,b);
}
int main() {
	int a=3,b=5;
	cout<<"First:"<<cal(a,b,add<decltype(a+b)>)<<endl;
	cout<<"Second:"<<cal(a,b,sub<decltype(a-b)>)<<endl;
	string s1 {"hello"};
	string s2 {"world"};
	cout<<"Third:"<<cal(s1,s2,add<string>)<<endl;
	return 0;
}
//output:
/*First:8
Second:-2
Third:helloworld*/
