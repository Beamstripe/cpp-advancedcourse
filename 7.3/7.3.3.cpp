#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int>data;
	data.push_back(1);
	data.push_back(3);
	data.push_back(2);
	sort(data.begin(),data.end());
	for( auto e :data)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}
//output:
//1 2 3
