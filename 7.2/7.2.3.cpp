#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
class Student {
	private:
		string name;
		string specialty;//??
		long id;// ??
		double creditPoint; //????
	public:
		Student(string n,string s,long i,double c)
			:name(n),specialty(s),id(i),creditPoint(c) {}
		void setCreditPoint(double c) {
			creditPoint=c;
		}
		double getCreditPoint()const {
			return creditPoint;
		}
		string getName()const {
			return name;
		}
		long getId()const {
			return id;
		}
		string getSpecialty()const {
			return specialty;
		}
		friend std::ostream& operator<<(std::ostream& out,const Student& s);
};
ostream& operator<<(ostream& out,const Student& s) {
	out<<"Name:"<<s.name<<endl;
	out<<" Id:"<<s.id<<endl;
	out<<" Specialty:"<<s.specialty<<endl;
	out<<" CreditPoint:"<<s.creditPoint<<endl;
	return out;
}
class StudentManage {
	public:
		enum SortType {BY_NAME,BY_ID,
		               BY_SPECIALTY,BY_CRDITPOINT
		              };
		StudentManage()=default;
		void addStudent();
		void removeStudent();
		void setSortType(SortType st);
		void findStudent();
		int size()const {
			return students.size();
		}
		friend std::ostream& operator<<(std::ostream& out,
		                                const StudentManage& sm);
	private:
		vector<Student> students;
		SortType sortType=BY_ID;
};
void StudentManage::setSortType (SortType st) {
	std::function<bool(const Student&,const Student&)> f;
	switch(st) {
		case BY_ID:
			f=[](const Student& s1,const Student& s2) {
				return s1.getName()<s2.getName();
			};
			break;
		case BY_NAME:
			f=[](const Student& s1,const Student& s2) {
				return s1.getId()<s2.getId();
			};
			break;
		case BY_SPECIALTY:
			f=[](const Student& s1,const Student& s2) {
				return s1.getSpecialty()<s2.getSpecialty();
			};
			break;
		case BY_CRDITPOINT:
			f=[](const Student& s1,const Student& s2) {
				return s1.getCreditPoint()<s2.getCreditPoint();
			};
			break;
	}
	sort(students.begin(),students.end(),f);
	sortType = st;
}
void StudentManage::addStudent() {
	string n,s;
	long i;
	double c;
	puts("Please input the name, speciality, id and the creditscore of the student");
	cin>>n>>s>>i>>c;
	for(int j=0; j<students.size(); j++) {
		if(students[j].getId()==i) {
			cout<<"The student already exists."<<endl;
			return;
		}
	}
	Student stu(n,s,i,c);
	students.push_back(stu);
	setSortType(BY_ID);
}
void StudentManage::removeStudent() {
	puts("Please input the id of the student of your query(delete)");
	long tag;
	bool ifFind=false;
	cin>>tag;
	for(auto it = students.begin(); it!=students.end(); it++) {
		if(tag==(*it).getId()) {
			students.erase(it);
			ifFind=true;
			break;
		}
	}
	if(!ifFind)puts("There is no such student"); 
}
void StudentManage::findStudent() {
	puts("Please input the id of the student of your query(find)");
	bool ifFind=false;
	if(sortType==BY_ID) {
		long tagid;
		cin>>tagid;
		for(int i=0; i<students.size(); i++) {
			if(students[i].getId()==tagid) {
				cout<<students[i];
				ifFind=true;
				break;
			}
		}
	} else if(sortType==StudentManage::BY_NAME) {
		string tagnm;
		cin>>tagnm;
		for(int i=0; i<students.size(); i++) {
			if(students[i].getName()==tagnm) {
				cout<<students[i];
				ifFind=true;
			}
		}
	}
	if(!ifFind)puts("There is no such student"); 
}
std::ostream& operator<<(std::ostream& out,const StudentManage& sm) {
//	sm.setSortType(sm.sortType);
	for(auto i : sm.students) {
		cout<<i;
	}
}
int main() {
	StudentManage sm;
	sm.addStudent();
	sm.addStudent();
	sm.addStudent();
	sm.addStudent();
	cout<<"sort type(0-name,1-id,2-specialty,3-creditpoint):";
	int choice;
	cin>>choice;
	sm.setSortType (static_cast<StudentManage::SortType>(choice));
	cout<<sm;
	sm.findStudent ();
	sm.removeStudent ();
	cout<<sm;
	return 0;
}
