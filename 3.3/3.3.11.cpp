#include <iostream>
using namespace std;
class Test {
	private:
		int a;
	public:
		Test() {
			cout<<"Default constructor!\n";
		}
		Test(int x):a(x) {
			cout<<"Constructor!\n";
		}
		Test(const Test& t) {
			a=t.a;
			cout<<"Copy constructor!\n";
		}
		Test(Test&& t) {
			a=t.a;
			cout<<"move copy constructor!\n";
		}
};
Test fun() {
	return Test(3);
}
int main() {
	Test t;
	Test t2=move(fun());
	return 0;
}
/*Default constructor!
Constructor!
move copy constructor!*/
