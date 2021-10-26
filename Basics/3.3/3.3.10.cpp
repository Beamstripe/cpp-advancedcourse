#include <iostream>
using namespace std;
class Test {
	private:
		int a,b;
	public:
		Test():Test(1) {
			cout<<"Constructor without parameter!\n";
		}
		Test(int x):Test(x,10) {
			cout<<"Constructor with 1 parameter!\n";
		}
		Test(int x,int y):a(x),b(y) {
			cout<<"Constructor with 2 paramter!\n";
		}
		void output()const {
			cout<<a<<","<<b<<endl;
		}
};
int main() {
	Test t;
	t.output();
	Test t1(3,5);
	t1.output();
	return 0;
}
/*Constructor with 2 paramter!
Constructor with 1 parameter!
Constructor without parameter!
1,10
Constructor with 2 paramter!
3,5*/
