#include <iostream>
using namespace std;
template <typename T>
class Array1D {
	public:
		Array1D (int newSize); //??????
		Array1D (T *p, int newSize); //????????????
		Array1D ( const Array1D <T>& a); //??????
		~Array1D ();
		int getSize()const; //???????
		T max()const; //????????
		void reverse(); //??????
		const T& operator[](int index)const;
		T& operator[](int index);
		Array1D& operator=(const Array1D<T>& a); //?????
		template <typename X>
		friend ostream& operator<<( ostream& out, const Array1D <X>& t);
	private:
		T *pData; //?????????
		int size; //??????
};
template <typename T>
Array1D<T>::Array1D(int newSize) {
	pData = new T[newSize];
	size=newSize;
}
template <typename T>
Array1D<T>::Array1D(T *p,int newSize) {
	pData = new T[newSize];
	*pData = *p;
	size=newSize;
}
template <typename T>
Array1D<T>::Array1D(const Array1D<T>& a) {
	pData = new T[a.getSize()];
	size=a.getSize();
	for(int i=0; i<size; i++) {
		*(pData+i)=a[i];
	}
}
template <typename T>
T& Array1D<T>::operator[](int index) {
	if(index<size) {
		return pData[index];
	} else{
		cout<<"Overflow!"<<endl;
	} exit(3);
}
template <typename T>
const T& Array1D<T>::operator[](int index)const {
	if(index<size) {
		return pData[index];
	} else{
		cout<<"Overflow!"<<endl;
	} exit(3);
}
template <typename T>
Array1D<T>::~Array1D() {
	delete[] pData;
}
template <typename T>
int Array1D<T>::getSize()const {
	return size;
}
template <typename T>
T Array1D<T>::max()const {
	T temp=(*pData);
	for(int i=1; i<size; i++) {
		if(temp<*(pData+i)) {
			temp=*(pData+i);
		}
	}
	return temp;
}
template <typename T>
void Array1D<T>::reverse() {
	int lt=0,rt=size-1;
	while(lt<rt) {
		swap(*(pData+lt),*(pData+rt));
		lt++,rt--;
	}
}
template <typename T>
Array1D<T>& Array1D<T>::operator=(const Array1D<T>& a) {
	T *p = pData;
	size=a.getSize();
	for(int i=0; i<size; i++) {
		*(p+i)=a[i];
	}
}
template <typename X>
ostream& operator<<(ostream& out,const Array1D<X>& t) {
	for(int i=0; i<t.size; i++) {
		out<<*(t.pData+i)<<' ';
	}
	return out;
}
int main() {
	Array1D <int> array(5);
	for(int i=0; i<array.getSize(); ++i)
		array[i]=i+1;	
	cout<<"Max: "<< array.max()<<endl;
	for(int i=0; i<array.getSize(); ++i)
		cout<<array[i]<< " ";
	cout<<endl;
	cout<<array;
	return 0;
}
