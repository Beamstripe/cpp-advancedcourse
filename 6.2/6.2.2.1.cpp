#include <iostream>
using namespace std;
class Stack {
	public:
		Stack(int size=100); //??????????
		~Stack();
		void push(int data); //???????
		int pop(); //?????????
		bool isEmpty()const; //????????
		bool isFull()const; //???????
	private:
		int *pData; //????????????
		int stackSize; //??????
		int top; //???????
};
Stack::Stack(int size) {
	pData=new int[size];
	stackSize=size;
	top=-1;
}
Stack::~Stack() {
	delete [] pData;
}
void Stack::push(int data) {
	if(isFull()) {
		cout<<"Stack is full!\n";
		exit(0);
	}
	top++;
	pData[top]=data;
}
int Stack::pop() {
	if(isEmpty()) {
		cout<<"Stack is empty!\n";
		exit(0);
	}
	int temp=pData[top];
	top--;
	return temp;
}
bool Stack::isEmpty()const {
	return top==-1;
}
bool Stack::isFull()const {
	return top==stackSize-1;
}
int main() {
	int array[10]= {1, 3, 2, 4};
	Stack s(4); //???? s,??????? 4
	int i;
	for(i=0; i<3; ++i)
		s.push(array[i]);
	while(!s.isEmpty())
		cout<<s.pop()<<' ';
	for( i=0; i<10; ++i)
		s.push(array[i]);
	cout<<endl;
	return 0;
}
//output:
/*2 3 1 Stack is full!*/

