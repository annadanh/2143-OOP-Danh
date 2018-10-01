/*
* Course: CMPS 2143 - OOP
*
* Purpose: Create and define the functions of myVector class
*
* @author Anna
* @version 1.1 10/1/2018
*/

#include <iostream>

using namespace std;

class myVector {
private:
	int *vPtr;      // int pointer to array
	int maxSize;    // max size of array
	int minSize;    // min size of array
	int index;      // current location to insert or remove
	int* _resize(int);

public:
	myVector(int size);
	void pushBack(int item);
	void pushBack(int *arr, int size);
	int popBack();
	double percentFull();
	int* resize(double);
	int* resize(int);

	void print();
	int size();
	void size(int);
	int vSize();

	// Implementation of [] operator.  This function must return a 
	// refernce as array element can be put on left side 
	int& operator[](int i)
	{
		if (i >= maxSize)
		{
			cout << "Error, index out of \n";
			exit(0);
		}
		else if (i >= index) {
			cout << "Warning: vector[" << i << "] is undefined ...\n";
		}
		return vPtr[i];
	}

	friend ostream& operator<<(ostream& os, myVector V) {
		for (int i = 0; i < V.index; i++) {
			os << V.vPtr[i] << " ";
		}
		//os<<"test"<<endl;
		return os;
	}
  
  // Implementation of + operator. Adds each element of two vectors together
  // and returns the value
	myVector operator+(const myVector& V2) {

		int min = 0;
		int max = 0;

		// which vector is bigger?
		if (index >= V2.index) {
			max = index;
			min = V2.index;
		}
		else {
			max = V2.index;
			min = index;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		if (max == V2.index) {
			newVector.index = V2.index;
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = V2.vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] += vPtr[i];
			}
		}else
			newVector.index = index;
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = vPtr[i];
			}
			for(int i = 0; i < min; i++){
				newVector.vPtr[i] += V2.vPtr[i];
			}

		return newVector;
	}

   // Implementation of - operator. Subtracts each element of two vectors
  // and returns the value
	myVector operator-(const myVector& V2) {

		int min = 0;
		int max = 0;

		// which vector is bigger?
		if (index >= V2.index) {
			max = index;
			min = V2.index;
		}
		else {
			max = V2.index;
			min = index;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		if (max == V2.index) {
			newVector.index = V2.index;
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = V2.vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] -= vPtr[i];
			}
		}
		else
			newVector.index = index;
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = vPtr[i];
			}
			for (int i = 0; i < min; i++) {
			newVector.vPtr[i] -= V2.vPtr[i];
			}

		return newVector;
	}

   // Implementation of * operator. Multiplies each element of a vector
  // by an integer and returns the value
	myVector operator*(int num) {
		int max = index;

		myVector newVector(max);
		newVector.index = index;
		
		for (int i = 0; i < max; i++)
			newVector.vPtr[i] = vPtr[i];

		for (int i = 0; i < max; i++)
			newVector.vPtr[i] *= num;

		return newVector;
	}

   // Implementation of * operator. Multiplies each element of two vectors together
  // and returns the value
	myVector operator*(const myVector& V2) {
		int min = 0;
		int max = 0;

		// which vector is bigger?
		if (index >= V2.index) {
			max = index;
			min = V2.index;
		}
		else {
			max = V2.index;
			min = index;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		if (max == V2.index) {
			newVector.index = index;
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = V2.vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] *= vPtr[i];
			}
		}
		else
			newVector.index = V2.index;
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = vPtr[i];
			}
			for (int i = 0; i < min; i++) {
			newVector.vPtr[i] *= V2.vPtr[i];
			}

		return newVector;
	}

   // Implementation of / operator. Divides each element of two vectors      
  // and returns the value
	myVector operator/(const myVector& V2) {
		int min = 0;
		int max = 0;

		// which vector is bigger?
		if (index >= V2.index) {
			max = index;
			min = V2.index;
		}
		else {
			max = V2.index;
			min = index;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		if (max == V2.index) {
			newVector.index = index;
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = V2.vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] /= vPtr[i];
			}
		}
		else
			newVector.index = V2.index;
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = vPtr[i];
			}
			for (int i = 0; i < min; i++) {
			newVector.vPtr[i] /= V2.vPtr[i];
			}

		return newVector;
	}

   // Implementation of = operator. Takes one vector and sets it equal to another
	void operator=(const myVector& V2) {

		index = V2.index;

		//sets each element int r to the same values as rhsVector
		for (int i = 0; i < index; i++)
			vPtr[i] = V2.vPtr[i];
	}

   // Implementation of == operator. Takes two vectors and compares them   
  // and returns a boolean true or false
	bool operator==(const myVector& V2) {

		//Checks to see if the vectors are the same length
		if (index != V2.index)
			return false;

		//Checks to see if all of the values are the same
		for (int i = 0; i < index; i++) {
			if (vPtr[i] != V2.vPtr[i])
				return false;
		}

		//This returns true if and only if
		//the lengths are the same and all values are the same.
		return true;
	}

};


/**
* Function constructor
*   Sets up the vector
* @param {int} size : initial size of vector
* @return void
*/
myVector::myVector(int size) {
	maxSize = size;
	minSize = size;
	// create the array of vSize
	vPtr = new int[maxSize];
	index = 0;
}

/**
* Function print
*   Prints the current values in the vector
* @param void
* @return void
*/
void myVector::print() {
	for (int i = 0; i < index; i++) {
		cout << vPtr[i] << " ";
	}
	cout << endl;
}

/**
* Function pushBack
*   Adds value to vector
* @param {int} item : integer value
* @return void
*/
void myVector::pushBack(int item) {
	if (index >= maxSize) {
		vPtr = resize(1.5);
	}
	vPtr[index++] = item;
}

void myVector::pushBack(int *A, int size) {
	for (int i = 0; i < size; i++) {
		pushBack(A[i]);
	}
}

/**
* Function popBack
*   Returns value from vector
* @param none
* @return {int} : last item on vector
*/
int myVector::popBack() {

	index--;

	if (index < 0) {
		//dammit
	}

	if (percentFull() <= .4) {
		vPtr = resize(.5);
	}

	return vPtr[index];
}

/**
* Function resize
*   Resizes our vector based on passed in ratio
* @param {double} ratio : new array size
* @return {int*} : pointer to new array
*/
int* myVector::resize(double ratio) {
	// figure out what our new size is, bigger or smaller
	int newSize = maxSize * ratio;

	return _resize(newSize);
}

int* myVector::resize(int size) {

	return _resize(size);

}

int* myVector::_resize(int newSize) {
	// Lets keep our vector above some minimum size
	if (newSize < minSize) {
		newSize = minSize;
	}

	// allocate new bigger vector
	int* vBigger = new int[newSize];

	//copy everything over
	for (int i = 0; i < index; i++) {
		vBigger[i] = vPtr[i];
	}

	// update new max size
	maxSize = newSize;

	// delete old memory
	delete[] vPtr;

	//return ptr to new memory
	return vBigger;
}

/**
* Function percentFull
*   helper function to calculate how full vector is
* @param none
* @return {double} : how full vector is
*/
double myVector::percentFull() {
	return double(index) / double(maxSize);
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
int myVector::size() {
	return index;
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
void myVector::size(int newSize) {
	vPtr = _resize(newSize);
}

/**
* Function vSize
*    Returns actual size of allocated memory
* @param none
* @return {int} : mem size
*/
int myVector::vSize() {
	return maxSize;
}

