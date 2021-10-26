#include <iostream>
#include <vector>
using namespace std;
class Element {
	private:
		int a;
	public:
		Element(int e=0):a(e) {}
		Element(const Element& e):Element(e.a) {
			cout<<"Copy constructor!\n";
		}
		Element(Element&& e):Element(e.a) {
			cout<<"Move copy constructor!\n";
		}
};
int main() {
	vector<Element> vec;
	vec.reserve(10);
	vec.push_back(Element(3));
	Element e(5);
	vec.push_back(e);
	return 0;
}
/*Move copy constructor!
Copy constructor!*/
