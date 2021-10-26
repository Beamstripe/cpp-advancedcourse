#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	map<string,int> counts;
	string word;
	while(cin>>word)
		++counts[word];
	for(auto e : counts)
		cout<<e.first<<"\t"<<e.second<<"\n";
	return 0;
}
//output:
/*hello   2
me      3*/
