#include <iostream>
using namespace std;
class Test {
	public:
		Test() {
			cout<<"Hello: "<<++i<<endl;
		}
		static int i;
};
int Test::i=0;
int main() {
	Test t[2];
	Test *p;
	p=new Test[2];
	return 0;
}
/*Hello: 1
Hello: 2
Hello: 3
Hello: 4*/
