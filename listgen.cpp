//Tudor Robaciu
//listgen.cpp

#include <iostream>
using std::cout; using std::endl;
#include <stdlib.h>
using std::rand; using std::srand;
#include <time.h>

//Creates a list of random numbers of a specified length with a certain range using time as the seed. 
//Inputs: [list_length] [min] [max]


int main(int argc, char* argv[]) {

	srand (time(NULL));

	int length = atoi(argv[1]), min = atoi(argv[2]), max = atoi(argv[3]);

	cout << length << endl;

	for (int x = 0; x < length; x++)
		cout << rand() % max + min << ' ';

	cout << endl;
}	
