#include <iostream>
#include "myVector.h"

using namespace std;

/**
* @purpose: The function creates a vector that holds integers 
*
* @param: int size - size of vector
* @return: nothing
*/
myVector::myVector(int size) {
	orgSize = size;
	vSize = size;
	// create the array of vSize
	theVector = new int[vSize];
	index = 0;
}

/**
* @purpose: The function prints the items in the vector
*
* @param: none
* @return: nothing
*/
void myVector::print() {
	for (int i = 0; i < index; i++) {
		cout << theVector[i] << " ";
	}
}

/**
* @purpose: The function pops items off the vector and resizes it
*
* @param: none
* @return: nothing
*/
void myVector::pop_back() {
	if (index == 0) {
		cout << "FALSE!! The vector is EMPTY!\n";
	}
	else {
		if (index < (double)vSize * .40 && index <= orgSize) {
			newSize = (double)vSize * .50;
			resize(newSize);
		}
		vSize--;
	}
}

/**
* @purpose: The function pushes items onto the vector and resizes if the vector isn't big enough
*
* @param: int item - value pushed onto vector
* @return: nothing
*/
void myVector::push_back(int item) {
	if (index >= vSize) {
		//cout << "Resizing the array!!" << endl;
		// 1. Create new array that is 1.5 times bigger
		newSize = (double)vSize * 1.5;
		resize(newSize);
	}
	theVector[index++] = item;
	//cout << index << endl;

}

/**
* @purpose: The function creates a new vector with a new size and copies the items from the myVector into it
*
* @param: int newSize - size of new array
* @return: nothing
*/
void myVector::resize(int newSize) {
	newVector = new int[newSize];
	// 2. Copy each item from myVector to new vector.
	for (int i = 0; i < vSize; i++) {
		newVector[i] = theVector[i];
	}
	// set vector size to new size
	vSize = newSize;
	// 3. Point temp pointer to old array
	tempVector = theVector;
	// 4. Point myVector to new array
	theVector = newVector;
	// 5. Delete old array
	delete[] tempVector;
}

/**
* @purpose: The function returns the size of the vector
*
* @param: none
* @return: vSize - size of vector
*/
int myVector::size() {
	return vSize;
}
