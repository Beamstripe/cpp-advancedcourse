#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	cout<<hex<<20<<endl;
	cout<<oct<<10<<endl;
	cout<<setfill('x')<<setw(10);
	cout<<100<<"aa"<<endl;
	return 0;
}
//output:
/*14
12
xxxxxxx144aa*/
