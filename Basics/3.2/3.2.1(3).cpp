#include <iostream>
using namespace std;
class TestClass {
	public:
		TestClass( int newValue=0) {
			value = newValue;
			cout<<"Value: "<<value<<", Constructed!\n";
		}
		TestClass( const TestClass & rhs) {
			value = rhs.value;
			cout<<"Value: "<<value<<", Copy Constructed!\n";
		}
		~TestClass() {
			cout<<"Value: "<<value<<", Destructed!\n";
		}
		void setValue( int newValue) {
			value = newValue;
		}
		int getValue()const {
			return value;
		}
	private:
		int value;
};
TestClass & fooFun(TestClass &t) {
	t.setValue(20);
	return t;
}
int main() {
	TestClass t1(10),t2(t1),t3;
	t3=fooFun(t1);
	return 0;
}
/*
Value: 10, Constructed!
Value: 10, Copy Constructed!
Value: 0, Constructed!
Value: 10, Copy Constructed!
Value: 20, Copy Constructed!
Value: 20, Destructed!
Value: 20, Destructed!
Value: 20, Destructed!
Value: 10, Destructed!
Value: 10, Destructed!
*/
