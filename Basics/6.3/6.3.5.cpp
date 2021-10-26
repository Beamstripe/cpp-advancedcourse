#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<typename T,typename V>
T search(T begin,T end,V value) {
	while(begin!=end) {
		if(*begin==value) return begin;
		begin++;
	}
	return end;
}
int main() {
	int a[3]= {5,9,10};
	auto it=search(begin(a),end(a),9);
	if(it==end(a)) cout<<"No\n";
	else
		cout<<*it<<" Yes\n";
	vector<string> v {"hello","world","welcome"};
	if(search(v.begin (),v.end (),"test")==v.end ())
		cout<<"No\n";
	else
		cout<<"Yes\n";
	return 0;
}
//output:
/*9 Yes
No*/
