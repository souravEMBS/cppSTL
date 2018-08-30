//============================================================================
// Name        : ittrAndAlgo.cpp
// Author      : Sourav
// Version     :
// Copyright   : Your copyright notice
// Description : Itterators and algorithms in C++, Ansi-style
//============================================================================

#include <iostream>

/* STL Headers */
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

template <typename t>
void printAnyList(t& myset, list<int>::iterator itr){
	cout<< "\n*** start of set ***" << endl;
	//for(itr = myset.begin(); itr != myset.end();++itr)
	cout << "set value is: " << *itr << endl;
	cout<< "*** end of set ***\n" << endl;
}

template <typename t>
void printVector(t& myset ){
	vector<int>::iterator itr;
	cout<< "\n*** start of set ***" << endl;
	for(itr = myset.begin(); itr != myset.end();++itr)
		cout << "set value is: " << *itr << endl;
	cout<< "*** end of set ***\n" << endl;
}

bool isOdd(int i)
{
	return i%2;
}
int main() {
	cout << "Itterators" << endl;

/*##################################################
 * 		Random access iterators (vector deque array)
 * #################################################
 */

	vector<int> vec = {1,55,21,4,32,65,99,-2,0,23};
	vector<int>::iterator itr;
	for(vector<int>::iterator itr =  vec.begin();itr!= vec.end();++itr)
	{
		if(*itr > 5)
			cout<<"vect: " << *itr << endl;
	}

/*##################################################
 * 		Bidirectional iterators (list, set, map)
 * #################################################
 */

	list<int> myList = {5,2,9};
	myList.push_back(6);
	myList.push_front(44);
	list<int>::iterator itrL =  find(myList.begin(),myList.end(),2);
	++itrL;
	printAnyList(myList,itrL);
	--itrL;
	printAnyList(myList,itrL);

/*##################################################
 * 					Algorithms
 * #################################################
 */

	vector<int>::iterator itrMin = min_element(vec.begin(),vec.end());
	cout<<"normal " << endl;
	printVector(vec);


	//sort
	cout<<"sort " << endl;
	itr = vec.begin();
	sort(vec.begin(),vec.end());
	printVector(vec);

	//reverse sort
	itr = vec.begin();
	itr = itr +3;
	cout<<"reverse " << endl;
	reverse(itr,vec.end());
	printVector(vec);

	//find
	itr = vec.begin();
	itr = find_if(vec.begin(),vec.end(),isOdd);
	cout << "is odd? " << *itr << endl;
	itr = itr + 3;
	itr = find_if(itr,vec.end(),isOdd);
	cout << "is odd? " << *itr << endl;
	return 0;
}
