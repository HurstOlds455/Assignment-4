//Tudor Robaciu
//Q1.cpp

#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::swap;
#include <ctime>
using std::clock_t; using std::clock;

//Tests the runtimes of insertion sort and quicksort.

void insertionSort (vector<int> values) {

	int base, index;

	for (unsigned int x = 2; x < values.size(); x ++) {
		
		base = values[x];
		index = x - 1;

		while (index > 0 && values[index] > base) {
			
			values[index + 1] = values[index];
			index -= 1;
		}

		values[index + 1] = base;
	}
};


//Partition uses the first element as the pivot.
int partition (vector<int>& values, int low, int high) {

	int pivot, left;
	
	pivot = values[low];
	left = low;

	for (int x  = low + 1; x <= high; x++) {
		
		if (values[x] < pivot) {
			left += 1;
			swap(values[x], values[left]);	
		}
	}

	swap(values[low], values[left]);
	return left;
};


void quickSort (vector<int> values, int low, int high) {
	
	int pivotIndex;

	if (high > low) {
		pivotIndex = partition(values, low, high);
		quickSort(values, low, pivotIndex - 1);
		quickSort(values, pivotIndex + 1, high);
	}
};


int main() {
	
	
	int length, newVal;
	vector<int> vals;

	cin >> length;

	for (int x = 0; x < length; x++) {	//Build vector.
		cin >> newVal;
		vals.push_back(newVal);
	}


	clock_t start = clock();		//Test insertion sort time.

	for (int y = 0; y <= 10000; y++)	//Runs 10,000 times to get a sizeable runtime.
		insertionSort(vals);

	clock_t end = clock() - start;


	cout << "Insertion sort time: " << ((double) end) / (double) CLOCKS_PER_SEC 
			<< " seconds" << endl;

	
	start = clock();			//Test quicksort time.
	
	for (int z = 0; z <= 10000; z++)
		quickSort(vals, 0, vals.size() - 1);

	end = clock() - start;

	cout << "Quicksort time: " << ((double) end) / (double) CLOCKS_PER_SEC
			<< " seconds" << endl;
}
