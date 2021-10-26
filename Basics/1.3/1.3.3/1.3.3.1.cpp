#include <iostream>
using namespace std;
int* getDiagonal(int **matrix,int n) {
	int* head;
	head= new int[n]; 
	for(int i=n-1;i>=0;i--){
		int t=matrix[i][i];
		head[i]=t;
	}
	return head;
}
int main() {
	int **data, n=5;
	data =new int*[n]; //Dynamically create pointer array
	for(int i=0; i<n; ++i)
		data[i]=new int[n]; //Each pointer array points to the one-dimention array
	for(int i=0; i<n; ++i) { //initiate the element
		for(int j=0; j<n; ++j)
			data[i][j]=i+j;
	}
	int *diagonal=getDiagonal(data,n);
	for(int i=0; i<n; ++i)
		cout<<diagonal[i]<<endl;
	delete[] diagonal; //free up the memory of the diagonal array
	for(int i=0; i<n; ++i) //free up the memory of two-dimention array
		delete[] data[i];
	delete[] data;
	return 0;
}
