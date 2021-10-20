#include <iostream>
#include <ctime>
using namespace std;
int add(int a,int b) {
	return a+b;
}
int sub(int a,int b) {
	return a-b;
}
int multiply(int a,int b) {
	return a*b;
}
int divide(int a,int b){
	return a/b;
}
char menu() {
	char choice;
	cout<<"1) add two number\n";
	cout<<"2) sub two number\n";
	cout<<"3) multiply two number\n";
	cout<<"4) divide two number\n";
	cout<<"0) quit\n";
	cout<<"Enter your choice:\n";
	cin>>choice;
	return choice;
}
bool answerQuestion(int num1,int num2,int (*f)(int ,int ), int answer ) {
	return f(num1,num2)==answer;
}
int main() {
	int total=0,correct=0;
	srand((unsigned)time(NULL));
	while(true) {
		char choice=menu();
		if(choice=='0'){
			cout<<"You have answered "<<total<<" questions."<<endl;
			cout<<"The correctness rate is "<<100.0*correct/total<<"%."<<endl;
			break;
		}
		int num1, num2;
		num1=rand()%90+10; //get integers between 10 and 99
		num2=rand()%90+10;
		decltype(add) *pf; //function pointer, deduce the type by "decltype"
		char op;
		switch(choice) {
			case '1':
				pf=add;
				op='+';
				break;
			case '2':
				pf=sub;
				op='-';
				break;
			case '3':
				pf=multiply;
				op='*';
				break;
			case '4':
				while(num1%num2!=0){
					num1=rand()%90+10;
					num2=rand()%90+10;
				}
				pf=divide;
				op='/';
				break;
			default:
				continue;
		}
		int answer;
		int trial=3;
		cout<<num1<<op<<num2<<"=?";
		total++;
		while(trial){
			cin>>answer;
			trial--;
			if(answerQuestion(num1,num2,pf,answer)==true)
			{
				cout<<"Correct!"<<endl;
				correct++;
				break;
			}
			else
				cout<<"Wrong!";
				if(trial)
					cout<<" Please try again"<<endl;
				else
					cout<<" Good luck next time"<<endl;
		}
		
	}
	return 0;
}
