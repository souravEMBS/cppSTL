//============================================================================
// Name        : Templates.cpp
// Author      : Sourav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <typename T>
T square(T x)
{
	return x*x;
}

template<typename T>
class SoVector{
	T arr[1000];
	int size;
public:
	SoVector():size(0){}
	void push(T x){	arr[size] = x; size++;	}
	T get(int i) const {return arr[i];}
	int getSize() const {return size;}
	void print() const {for(int i = 0;i<size;i++) {cout << arr[i] << endl;}}
};

template<typename T>
SoVector<T> operator*(const SoVector<T>& rhs1, SoVector<T>& rhs2){
	SoVector<T> ret;
	int size = rhs1.getSize();
	for(int i=0; i<size;i++){
		ret.push(rhs1.get(i)*rhs2.get(i));
	}
	return ret;
}

int main() {
	cout << square(5) << endl;//function templates can infer the data type
	cout << square(5.5) << endl;

	SoVector<int> sb;//class template data type need to be explicit
	sb.push(33);
	sb.push(45);
	sb.push(23);
	sb.push(50);
	sb.print();

	cout << "print squared bv: " << endl;
	sb = square(sb);
	sb.print();
	return 0;
}
