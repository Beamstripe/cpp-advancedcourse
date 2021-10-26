#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;
class MyString {
	public:
		MyString(char *s) {
			str=new char[strlen(s)+1];
			strcpy(str,s);
		}
		MyString() {
			str=nullptr;
		}
		MyString(const MyString& s);
		MyString(MyString&& s);
		~MyString();
		MyString& operator=(const MyString& s);
		MyString& operator=(MyString&& s);
		int size()const;
		MyString operator+(const MyString& s)const;
		MyString operator+(const char* s)const;
		char& operator[](int index);
		const char& operator[](int index) const;
		friend ostream& operator<<( ostream& out,const MyString& s);
	private:
		char *str;
};
MyString::MyString(MyString&& s){
	str=new char[1000];
	strcpy(str,s.str);
}
MyString::MyString(const MyString& s){
	str=new char[1000];
	str=s.str;
}
MyString::~MyString(){
	if(str!=nullptr)
	delete[] str;
}
int MyString::size()const{
	return strlen(str);
}
char& MyString::operator[](int index){
	if(index<size())
	return str[index];
	else{
		cout<<"terminate called after throwing an instance of 'std::out_of_range'\nwhat():  MyString::_M_range_check: __n (which is "<<index<<") >= this->size() (which is "<<size()<<")"<<endl;
		exit(3);
	}
}
const char& MyString::operator[](int index)const{
	if(index<size()){
		char c=str[index];
		return c;
	}
	else{
		cout<<"terminate called after throwing an instance of 'std::out_of_range'\nwhat():  MyString::_M_range_check: __n (which is "<<index<<") >= this->size() (which is "<<size()<<")"<<endl;
		exit(3);
	}
}
MyString& MyString::operator=(const MyString& s){
	str=s.str;
	return (*this);
}
MyString& MyString::operator=(MyString&& s){
	for(int i=0;i<s.size();i++){
		str[i]=s[i];
	}
	return (*this);
}
MyString MyString::operator+(const MyString& s)const{
	int len=size();
	MyString temp;
	temp.str=new char[s.size()+len+1];
	for(int i=0;i<len;i++){
		temp.str[i]=str[i];
	}
	for(int i=0;i<s.size();i++){
		temp.str[len+i]=s[i];
	}
	temp.str[len+s.size()]='\0';
	return temp;
}
MyString MyString::operator+(const char* s)const{
	int len=size();
	MyString temp;
	temp.str=new char[strlen(s)+len+1];
	for(int i=0;i<len;i++){
		temp.str[i]=str[i];
	}
	for(int i=0;i<strlen(s);i++){
		temp.str[len+i]=s[i];
	}
	temp.str[len+strlen(s)]='\0';
	return temp;
}
ostream& operator<<(ostream& out,const MyString& s){
	out<<s.str;
	return out;
}
int main() {
	MyString s("Hello");
	MyString s1("p0709");
	s1=s;
	s1=s1+"opoo";
	cout<<s1<<endl;
	cout<<"!!!!"<<endl; 
	cout<<s<<endl;
	MyString s2=s+"World";
	cout<<s2<<endl;
	cout<<"Index 5:"<<s2[5]<<endl;
	return 0;
}
