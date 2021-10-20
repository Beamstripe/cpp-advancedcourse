#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class Array1D {
	private:
		vector<T> vec;
	public:
		Array1D(int size) {
			vec.resize (size);
		}
		T& operator[](int index) {
			return vec[index];
		}
		const T& operator[](int index)const {
			return vec[index];
		}
		int size()const {
			return vec.size ();
		}
};
int main() {
	Array1D<int> a(10);
	cout<<"size:"<<a.size ()<<endl;
	for(int i=0; i<a.size (); ++i)
		a[i]=i*i;
	for(int i=0; i<a.size(); ++i)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
//output:
/*size:10
0 1 4 9 16 25 36 49 64 81*/
