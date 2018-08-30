//============================================================================
// Name        : sequenceContainers.cpp
// Author      : Sourav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
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

int main() {

	/* #######################
	 * vectors only back entry
	 * ####################### */
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(10);

	cout << vec[2] << endl;
	cout <<vec.at(2) << endl;

	for(vector<int>::iterator itr =  vec.begin();itr!= vec.end();++itr)
		cout<<*itr << " itr" << endl;

	for(it: vec) //c++ 11
		cout << it << " it" << endl;

	int* p = &vec[0];
	cout << p[2] << endl;

	if(vec.empty()) {
		cout << "Not possible. \n" << endl;
	}

	cout << vec.size() << endl;

	vector<int> vec2(vec); //copy from vec

	vec.clear(); //clears vec

	for(it: vec) //c++ 11
			cout << it << " it" << endl;

	/* #######################
	 * Deque front and back entry
	 * ####################### */

	deque<int> deq = {4,6,7};
	deq.push_front(2);
	deq.push_back(3);

	//Deque has similar interface as with vectors
	cout << deq[1] << endl;

	/* #######################
	 * List or a doublly linked list
	 * ####################### */

	list<int> myList = {5,2,9};
	myList.push_back(6);
	myList.push_front(44);


	//find is a algorithm function to find the item of 2
	//slow search, slower than vector
	list<int>::iterator itr = find(myList.begin(),myList.end(),2);

	myList.insert(itr, 8); // fast instertion
	itr++;
	myList.erase(itr);//fast removal

	list<int> myList1 = { 2,4,3,5,6,1,3,6};
	list<int> myList2;

	myList1.splice(itr,myList2);

	for(itr: myList) //c++ 11
		cout << itr << " myList" << endl;

	for(itr: myList1) //c++ 11
			cout << itr << " myList1" << endl;

	for(itr: myList2) //c++ 11
				cout << itr << " myList2" << endl;


	cout << "seq Containers" << endl; // prints !!!Hello World!!!
	return 0;
}
