#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
class RandomNum {
	public:
		RandomNum(); //set seed using system time
		RandomNum(unsigned int seed); //set seed with parameter
		void setSeed(unsigned int seed); //set seed with parameter
		int random(); //generate 0~RAND_MAX random integer
		int random(int max); //generate 0~max random integer(max excluded)
		double frandom(); //generate 0~1.0 random double(1.0 excluded)
};
void RandomNum::setSeed(unsigned int seed) {
	srand(seed);
}
RandomNum::RandomNum() {
	setSeed(time(NULL));
}
RandomNum::RandomNum(unsigned int seed) {
	setSeed(seed);
}
int RandomNum::random() {
	return rand();
}
int RandomNum::random(int max) {
	return rand()%max;
}
double RandomNum::frandom() {
	return 1.0*rand()/RAND_MAX;
}
int main() {
	RandomNum randomGenerator;
	int i;
	for(i=0; i<100; ++i)
		cout<<randomGenerator.random(100)<<' ';
	cout<<"\n";
	for(i=0; i<100; ++i)
		cout<<randomGenerator.frandom()<<' ';
	cout<<"\n";
	return 0;
}

