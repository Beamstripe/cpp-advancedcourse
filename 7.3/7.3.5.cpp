#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;
double arithMean(const list<int>& nums) {
	double sum=accumulate(nums.begin(),nums.end(),0);
	return sum/nums.size();
}
int main() {
	list<int> data;
	data.push_back(2);
	data.push_back(3);
	data.push_back(1);
	data.push_back(4);
	cout<<"mean:"<<arithMean(data)<<endl;
	return 0;
}
//output:
//mean:2.5
