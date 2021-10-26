#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
	vector<Fraction> vec {{3,5},{2,7},{1,8}};
	ofstream f("d:\\tmp.txt");
	if(!f) return -1;
	f<<vec.size ()<<endl;
	for_each(vec.begin (),vec.end (), [&f](const Fraction& e) {
		f<<e.getNum()<<" "<<e.getDen()<<endl;
	});
	return 0;
}
//output(tmp.txt):
/*3
3 5
2 7
1 8*/

