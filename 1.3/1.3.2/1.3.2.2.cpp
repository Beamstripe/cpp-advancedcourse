#include <iostream>
#define MAXN 1000
using namespace std;
int getMax(int array[],int size){
	int ans=array[0];
	for(int i=1;i<size;i++){
		ans=ans>array[i]?ans:array[i];
	}
	return ans;
}
int main(){
	int n;
	int arr[MAXN];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//test output
	cout<<getMax(arr,n);
	return 0;
}
