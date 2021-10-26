#include <iostream>
#include <string>
using namespace std;
template <typename T>
void f(const T& a,const T& b) {
	cout<<a+b<<endl;
}
int main() {
	string s="Time",t="Marches";
	f(4,5);
	f(s,t);
	return 0;
}
//output:
/*9
TimeMarches*/
