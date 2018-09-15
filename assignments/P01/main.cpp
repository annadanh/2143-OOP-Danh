/**
* Course: 2143-OOP
* Assignment: P01
* Purpose: The program uses a class that implements the functionality of a C++ vector using 
* an array as the storage container. It grows and shrinks as items are added and removed.
*
* Author: Anna Danh
* Date: 9/13/18
*/


#include <iostream>
#include "myVector.h"

using namespace std;

int main() {

	myVector V(10);

	V.print();

	cout << "There are " << V.size() << " items in the vector.\n";

	V.pop_back();

	V.push_back(13);
	V.push_back(31);
	V.push_back(73);

	V.print();
	cout << "\n";

	
	for(int i = 0; i < 10000; i++) {
		V.push_back(rand() % 100);
	}

	cout << "There are " << V.size() << " items in the vector.\n";

	for (int i = 0; i < 9998; i++) {
		V.pop_back();
	}

	cout << "There are " << V.size() << " items in the vector.\n";

	V.print();
	
	system("pause");
}
