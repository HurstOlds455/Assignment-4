//Tudor Robaciu
//Q3.cpp

#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <ctime>
using std::clock_t;
#include <set>
using std::multiset; 
#include <unordered_set>
using std::unordered_multiset;
#include <vector>
using std::vector;


//This program tests the runtime for inserting values into a multiset vs. an unordered multiset.

int main() {

	multiset<int> btree;
	unordered_multiset<int> htable;
	vector<int> vals;
	int length, newVal;

	cin >> length;

	for (int x = 0; x < length; x++) {	//Build vector.
		cin >> newVal;
		vals.push_back(newVal);
	}


	clock_t start = clock();		//Multiset test.

	for (auto x: vals)
		btree.insert(x);

	clock_t end = clock() - start;


	cout << "Multiset time: " << ((double) end) / (double) CLOCKS_PER_SEC 
			<< " seconds" << endl;



	start = clock();			//Unordered multiset test.

	for (auto x: vals)
		htable.insert(x);
		
	end = clock() - start;


	cout << "Unordered multiset time: " << ((double) end) / (double) CLOCKS_PER_SEC 
			<< " seconds" << endl;
}

