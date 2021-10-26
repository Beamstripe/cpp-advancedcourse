#include <iostream>
#define MAXN 1000
using namespace std;
void reverse(int array[],int size){
	int t;
	for(int i=0;i<size/2;i++){
		t=array[i];
		array[i]=array[size-i-1];
		array[size-i-1]=t;
	}
}
int main(){
	int n;
	int arr[MAXN];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	reverse(arr,n);
	//test output
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	return 0;
}
