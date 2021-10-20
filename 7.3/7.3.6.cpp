#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
int product(int num1, int num2) {
	return num1*num2;
}
double geoMean(const list<int>& nums) {
	double mult=accumulate(nums.begin(),nums.end(),1,product);
//pow ???? mult ? 1.0/nums.size()??
	return pow(mult, 1.0/nums.size());
}
int main() {
	list<int> data;
	data.push_back(2);
	data.push_back(4);
	data.push_back(1);
	cout<<"mean:"<<geoMean(data)<<endl;
	return 0;
}
//output:
//mean:2
