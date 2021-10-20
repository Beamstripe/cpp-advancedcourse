#include <iostream>
using namespace std;
class Person {
	public:
		Person() {
			cout<<"Person Constructor "<<endl;
		}
		~Person() {
			cout<<"Person Destructor "<<endl;
		}
};
class Student : public Person {
	public:
		Student() {
			cout<<"Student Constructor "<<endl;
		}
		~Student() {
			cout<<"Student Destructor "<<endl;
		}
};
class Teacher : public Person {
	public:
		Teacher() {
			cout<<"Teacher Constructor "<<endl;
		}
		~Teacher() {
			cout<<"Teacher Destructor "<<endl;
		}
};
int main() {
	Student s;
	Teacher t;
	return 0;
}
//output:
/*Person Constructor
Student Constructor
Person Constructor
Teacher Constructor
Teacher Destructor
Person Destructor
Student Destructor
Person Destructor*/
