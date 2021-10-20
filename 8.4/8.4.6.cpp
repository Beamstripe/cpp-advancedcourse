#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Fraction {
	private:
		int num,den;
	public:
		Fraction(int n,int d):num(n),den(d) {}
		void output()const {
			cout<<num<<"/"<<den<<endl;
		}
		int getNum()const {
			return num;
		}
		int getDen()const {
			return den;
		}
};
int main() {
	vector<Fraction> vec;
	ifstream f("tmp.txt");
	if(!f) return -1;
	int size;
	f>>size;
	for(int i=0; i<size; ++i) {
		int num,den;
		f>>num>>den;
		vec.push_back (Fraction(num,den));
	}
	for(auto e:vec) e.output();
	cout<<endl;
	return 0;
}
//output:
/*2/9
3/7
1/4*/
