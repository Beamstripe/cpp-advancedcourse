#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int main( ) {
	map<int, int> myMap;
	myMap.insert(make_pair(5, 50));
	myMap.insert(make_pair(6, 60));
	myMap.insert(make_pair(4, 40));
	myMap.insert(make_pair(7, 70));
	for_each(myMap.begin(), myMap.end(),
	[](const pair<int,int>& e) {
		cout<<e.first<<"->"<<e.second<<endl;
	});
	return (0);
}
//output:
/*4->40
5->50
6->60
7->70*/
