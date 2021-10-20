#include <iostream>
using namespace std;
void xhg(int *a,int *b) {
	int *tmp;
	tmp=b;
	b=a;
	a=tmp;
	cout<<*a<<' '<<*b<<endl;
}
int main() {
	int x(5),y(4);
	xhg(&x,&y);
	cout<<x<<' '<<y<<endl;
	return 0;
}
//4 5
//5 4
