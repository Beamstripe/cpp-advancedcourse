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
	vector<int>::iterator it=data.begin();
	for(; it!=data.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}
//output:
//1 2 3
