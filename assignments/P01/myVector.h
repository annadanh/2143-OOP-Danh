#include <iostream>

using namespace std;

class myVector {
private:
	int *theVector;
	int vSize;
	int index;
	int *tempVector;
	int newSize;
	int *newVector;
	void resize(int newSize);
	int orgSize;
public:
	myVector(int size);
	void push_back(int item);
	void pop_back();
	void print();
	int size();
};

