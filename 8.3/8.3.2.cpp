#include <iostream>
using namespace std;
class ExceptionBase {
	public:
		virtual void showReason( ) {
			cout<<"Base Exception!\n";
		}
};
class PushOnFull: public ExceptionBase {
	public:
		void showReason() {
			cout<<"The stack is full!"<<endl;
		}
};
class PopOnEmpty: public ExceptionBase {
	public:
		void showReason() {
			cout<<"The stack is empty!"<<endl;
		}
};
class IllegalParameter:public ExceptionBase {
		void showReason() {
			puts("Illegal stack size!(should be positive)");
		}
};
template <typename T>
class Stack {
	public:
		Stack(int size=100);
		~Stack();
		void push(T data);
		T pop();
		bool isEmpty()const;
		bool isFull()const;
	private:
		T *pData;
		int stackSize;
		int top;
};
template <typename T>
Stack<T>::Stack(int size) {
	if(size<=0) {
		throw IllegalParameter();
	}
	pData=new T[size];
	stackSize=size;
	top=-1;
}
template <typename T>
Stack<T>::~Stack() {
	delete [] pData;
}
template <typename T>
void Stack<T>::push(T data) {
	if(isFull()) {
		throw PushOnFull();
	}
	top++;
	pData[top]=data;
}
template <typename T>
T Stack<T>::pop() {
	if(isEmpty()) {
		throw PopOnEmpty();
	}
	T temp=pData[top];
	top--;
	return temp;
}
template <typename T>
bool Stack<T>::isEmpty()const {
	return top==-1;
}
template <typename T>
bool Stack<T>::isFull()const {
	return top==stackSize-1;
}
//1
/*int main() {
	int array[10]= {1, 3, 2, 4};
	Stack<int> s(4); //???? s,??????? 4
	int i;
	try{
		for(i=0; i<3; ++i)
			s.push(array[i]);
		while(!s.isEmpty())
			cout<<s.pop()<<' ';
		for( i=0; i<10; ++i)
			s.push(array[i]);
		cout<<endl;
	}
	catch(ExceptionBase& e){
		e.showReason();
	}
	return 0;
}*/
//2
int main() {
	int array[10]= {1, 3, 2, 4};
	int size;
	cout<<"Input Stack Size:";
	cin>>size;
	try {
		Stack<int> s(size);
		for(int i=0; i<3; ++i)
			s.push(array[i]);
		while(!s.isEmpty())
			cout<<s.pop()<<' ';
	}
	catch(ExceptionBase & e) {
		e.showReason();
	}
	return 0;
}


