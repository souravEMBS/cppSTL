//============================================================================
// Name        : associativeContainer.cpp
// Author      : Sourav
// Version     :
// Copyright   : Your copyright notice
// Description : Associagtive container in C++, Ansi-style
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
void printAnyset(t& myset ){
	set<int>::iterator itr;
	cout<< "\n*** start of set ***" << endl;
	for(itr = myset.begin(); itr != myset.end();++itr)
			cout << "set value is: " << *itr << endl;
	cout<< "*** end of set ***\n" << endl;
}

template <typename t>
void printAnymap(t& mymap ){
	map<char,int>::iterator itr;
	cout<< "\n*** start of set ***" << endl;
	for(itr = mymap.begin(); itr != mymap.end();itr++)
		cout << (*itr).first << "=>" << (*itr).second << endl;
	cout<< "*** end of set ***\n" << endl;
}

//associative container is implementated using binary tree
/*set and multiset are sorted so the values of the elements
 * cannot be modified
 */

int main() {
	cout << "Associative Containers" << endl;

	/*#######################################
	 * 					set
	 * ######################################
	 */

	set<int> myset;
	myset.insert(3);//myset: {3}
	myset.insert(1);//{1,3} always a sorted insert
	myset.insert(7);//{1,3,7} O(log(n))

	set<int>::iterator it;
	it = myset.find(1); //O(log(n)) for find

	cout << "value found at: "  << endl;

	pair<set<int>::iterator, bool> ret;
	ret = myset.insert(3); // set doesent allow duplicate item so insertion fails
	if(ret.second == false){
		it=ret.first;
		cout << "insetion failed" << endl;
	}

	myset.insert(it,9);
	set<int>::iterator itr;
	printAnyset(myset);
//	for(itr = myset.begin(); itr != myset.end();++itr)
//		cout << "set value is: " << *itr << endl;

	myset.erase(it);
	printAnyset(myset);

	myset.erase(1);
	printAnyset(myset);

	/*#######################################
	 * 				multiset
	 * ######################################
	 */

	multiset<int> myMultiSet = {2,4,44,22,11,4,2,1,99}; //unlike sets it allows duplicates
	printAnyset(myMultiSet);

	/*#######################################
	 * 			map and multimap hash
	 * ######################################
	 */

	map<char,int> mymap;
	mymap.insert(pair<char,int>('a',100));
	mymap.insert(make_pair('b',200));

	//printAnyset(mymap);

	map<char,int>::iterator it1 = mymap.begin();
	mymap.insert(it1,pair<char,int>('z',300));
	it1 = mymap.find('z'); //finding value from key

	printAnymap(mymap);

	return 0;
}
