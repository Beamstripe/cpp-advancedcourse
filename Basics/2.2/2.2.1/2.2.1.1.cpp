#include <iostream>
using namespace std;
class TestClass {
	public:
		TestClass(int a) {
			aa=a;
			cout<<aa<<" Constructed!\n";
		}
		~TestClass() {
			cout<<aa<<" Destructed!\n";
		}
	private:
		int aa;
};
TestClass AA(3); //Global object
int main() {
	cout<<"In MainFunction."<<endl;
	TestClass BB(5);
	return 0;
}
/*
3 Constructed!
In MainFunction.
5 Constructed!
5 Destructed!
3 Destructed!
*/
