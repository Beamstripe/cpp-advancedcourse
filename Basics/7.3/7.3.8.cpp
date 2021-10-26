#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
int main( ) {
	vector<int> myVector;
	myVector.push_back(50);
	myVector.push_back(76);
	myVector.push_back(68);
	for_each(myVector.begin(), myVector.end(),
	[](int e) {
		cout<<e<<" ";
	});
	cout << endl;
	transform(myVector.begin(), myVector.end(), myVector.begin(),
	          bind(plus<int>(), _1,10));
	for(auto e : myVector) cout<<e<<" ";
	cout << endl;
	return (0);
}
//output:
/*50 76 68
60 86 78*/
