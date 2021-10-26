#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
//1
/*bool predicate(int data){
	if(data%3==0&&data<=20)return true;
	else return false;
}*/
//-------------------------
//2
/*class Predicate{
	public: 
	bool operator()(int data){
		if(data%3==0&&data<=20)return true;
		else return false;
	}
};*/
//4
/*class Predicate{
	public: 
	static int cnt;
	bool operator()(int data){
		if(data%3==0&&data<=20&&cnt<3){
			cnt++;
			return true;
		}
		else return false;
	}
};
int Predicate::cnt=0;*/

int main() {
	vector<int> vec {2,4,5,6,10,15,3,21,36,72,9,13};
	vector<int> result;
	result.resize (vec.size());
//1
//	auto end=copy_if(vec.begin (),vec.end (),result.begin(),predicate);
//2,4
//	auto end=copy_if(vec.begin (),vec.end (),result.begin(),Predicate());
//3
	/*auto end=copy_if(vec.begin (),vec.end (),result.begin(),
	[](const int& x){
		if(x%3==0&&x<=20)return true;
		else return false;
	});*/
//5
	int cnt=0;
	auto end=copy_if(vec.begin (),vec.end (),result.begin(),
	[&cnt](const int& x){
		if(x%3==0&&x<=20&&cnt<3){
			cnt++;return true;
		}
		else return false;
	});
	result.erase(end,result.end ());
	for_each(result.begin (),result.end (),[](int e) {
		cout<<e<<endl;
	});
	return 0;
}
