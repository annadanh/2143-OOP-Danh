/*
*Course: CMPS 2143 - OOP
*
*Purpose: Overload operators to manipulate myVector class
*
*@author Anna Danh
*@version 1.1 10/1/18
*@github https://github.com/annadanh/2143-OOP-Danh
*/



#include <iostream>
#include "myVector.h"

using namespace std;


int main() {
	myVector v1(10);
	myVector v2(20);

	v1.pushBack(8);
	// v1 contains: [8]

	v2.pushBack(10);
	v2.pushBack(20);
	v2.pushBack(30);
	// v2 contains: [10,20,30]

	// Declare some int array
	int A[] = { 1,2,3,4,5 };


	v1.pushBack(A, 5);
	// v1 contains: [8,1,2,3,4,5]

	v1 = v1 + v2;
	// v1 contains: [18,21,32,3,4,5]

	cout << v1 << endl;
	// would print: [18,21,32,3,4,5] to standard out.

	cout << v1[2] << endl;
	// would print: 32 to standard out.


	v2 = v2 * 3;
	// v2 contains: [30,60,90]

	v2 = v2 * v1;
	// v2 contains: [540,1260,2880]

	v2[2] = 100;
	// V2 contains: [540,1260,100]

	// push values onto v2
	v2.pushBack(2);
	v2.pushBack(35);
	v2.pushBack(200);

	(v1 - v2).print();
	// should be [-522,-1239,-68,1,-31,-195] 
	(v1 / v2).print();
	// should be [0,0,0,1,0,0]
	(v2 / v1).print();
	// should be [30,60,3,0,8,40]

	// tests if v1 and v2 are equal
	if (v1 == v2) {
		cout << "v1 and v2 are equal \n";
	}
	else
		cout << "v1 and v2 are not equal\n";

	system("pause");

}
