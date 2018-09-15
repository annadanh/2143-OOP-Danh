/**
* Author: Anna Danh
* Course: 2143-OOP
* Assignment: P01
* Purpose: The program uses a class that implements the functionality of a C++ vector using 
* an array as the storage container. It grows and shrinks as items are added and removed.
*
* Date: 9/13/18
*/


#include <iostream>
#include "myVector.h"

using namespace std;

int main() {

	myVector V(10);

	V.print();

	// prints current size of vector
	cout << "There are " << V.size() << " items in the vector.\n";

	// attempt to remove from empty vector
	V.pop_back();

	// push values into vector
	V.push_back(13);
	V.push_back(31);
	V.push_back(73);

	V.print();
	cout << "\n";

	// push 10,000 random values into the vector
	for(int i = 0; i < 10000; i++) {
		V.push_back(rand() % 100);
	}

	// print current size of vector
	cout << "There are " << V.size() << " items in the vector.\n";

	// pop 9,998 items off the vector
	for (int i = 0; i < 9998; i++) {
		V.pop_back();
	}

	// print current size of vector
	cout << "There are " << V.size() << " items in the vector.\n";

	// print items in vector
	V.print();
	
	system("pause");
}
