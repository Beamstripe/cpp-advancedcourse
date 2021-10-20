#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char buf[100];
	cin>>buf;
	ofstream of;
	of.open("1.txt");
	of<<buf;
	of.close();
	return 0;
}
//output:(1.txt)
//Every
