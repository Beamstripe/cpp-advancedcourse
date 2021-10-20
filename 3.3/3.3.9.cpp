#include <iostream>
//No null-parameter constructor
class Test {
	private:
		int a;
	public:
		Test(const Test& t)=default;
//		Test()=default;		(solution)
};
int main() {
	Test t;
	return 0;
}
