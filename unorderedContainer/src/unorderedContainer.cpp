//============================================================================
// Name        : unorderedContainer.cpp
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

template <typename t>
void printAnyUoSet(t& myset ){
	unordered_set<string>::iterator itr;
	cout<< "\n*** start of set ***" << endl;
	for(itr = myset.begin(); itr != myset.end();++itr)
			cout << "set value is: " << *itr << endl;
	cout<< "*** end of set ***\n" << endl;
}

int main() {
	cout << "Unordered Containers" << endl;

/*#######################################
 * 			unordered set
 * ######################################
 */
	unordered_set<string> myUoSet = {"red", "green", "blue"};
	unordered_set<string>::const_iterator itr = myUoSet.find("green");
	if(itr != myUoSet.end()) //dereferencing the end ittr result undefined behaviour
		cout << *itr << endl;

	myUoSet.insert("yellow");

	vector<string> vec = {"purple","pink"};
	myUoSet.insert(vec.begin(), vec.end());

	printAnyUoSet(myUoSet);

	/*Hash table specific API*/
	//load factor- ratio of total number of elements to total number of buckets

	cout << "load_factor: " << myUoSet.load_factor() << endl;
	string x = "red";
	cout << x << " is in bucket #" << myUoSet.bucket(x) << endl;
	cout << "Total bucket #" << myUoSet.bucket_count() << endl;

	return 0;
}
