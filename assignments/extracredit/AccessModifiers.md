## Access Modifiers in C++

Access modifiers are used to implement an important feature of Object Oriented Programming known as **Data Hiding**. Consider a real-life example: Consider Indian secret informatic system having 10 senior members, have some top secret regarding national security. So we can think that 10 people as class data members or member functions who can directly access secret information from each other But anyone can’t access this information other than this 10 members i.e. outside person can’t access information directly without having any privileges, This is what data hiding is.
Access modifiers or Access Specifiers in a class are used to set the accessibility of the class members. That is, it sets some restrictions on the class members not to get directly accessed by the outside functions.

There are 3 types of access modifiers available in C++:

1. **Public**
2. **Private**
3. **Protected**

**Note**: If we do not specify any access modifiers for the members inside the class then by default the access modifier for the members will be **Private**.

Let us now look at each one these access modifiers in details:

* **Public**: All the class members declared under public will be available to everyone. The data members and member functions declared public can be accessed by other classes too. The public members of a class can be accessed from anywhere in the program using the direct member access operator (.) with the object of that class.

``` c++ 
// C++ program to demonstrate public 
// access modifier 

#include<iostream> 
using namespace std; 

// class definition 
class Rectangle 
{ 
	public: 
		int x;
  		int y;
		
		int compute_perimeter() 
		{ 
			return (2*x)+(2*y); 
		} 
	
}; 

// main function 
int main() 
{ 
	Rectangle obj; 
	
	// accessing public datamember outside class 
	obj.x = 5; 
 obj.y = 10;
	
	cout << "x is:" << obj.x << '\n';
 cout << "y is:" << obj.y << '\n'; 
	cout << "Perimeter is:" << obj.compute_perimeter(); 
	return 0; 
} 

```
Output:
```
x is:5
y is:10
Perimeter is:30
```

In the above program the data member radius is public so we are allowed to access it outside the class.

* **Private**: The class members declared as **private** can be accessed only by the functions inside the class. They are not allowed to be accessed directly by any object or function outside the class. Only the member functions or the friend functions are allowed to access the private data members of a class.
Example:

 
``` c++
// C++ program to demonstrate private 
// access modifier 

#include<iostream> 
using namespace std; 

class Rectangle 
{ 
	// private data member 
	private: 
		int x;
  int y;
	
	// public member function	 
	public:	 
		int compute_perimeter() 
		{ // member function can access private 
			// data member radius 
			return (2*x)+(2*y); 
		} 
	
}; 

// main function 
int main() 
{ 
	// creating object of the class 
	Rectangle obj; 
	
	// trying to access private data member 
	// directly outside the class 
	obj.x = 5;
 obj.y = 10;
	
	cout << "Perimeter is:" << obj.compute_perimeter(); 
	return 0; 
} 
```

The output of above program will be a compile time error because we are not allowed to access the private data members of a class directly outside the class.
Output:
```
prog.cpp: In function 'int main()':
prog.cpp:11:7: error: 'int Rectangle::x' is private
   int x;
       
prog.cpp:32:6: error: within this context
  obj.x = 5;
      
prog.cpp:12:9: error: 'int Rectangle::y' is private
     int y;
         
prog.cpp:33:8: error: within this context
    obj.y = 10;
```

However we can access the private data members of a class indirectly using the public member functions of the class. Below program explains how to do this:

``` c++ 
// C++ program to demonstrate private 
// access modifier 

#include<iostream> 
using namespace std; 

class Rectangle 
{ 
	// private data member 
	private: 
		int x;
  		int y;
	
	// public member function	 
	public:	 
		int compute_perimeter(int l, int w) 
		{ // member function can access private 
			// data member radius 
			x = l; 
  	y = w;
			
			int perimeter = (2*x)+(2*y); 
			
			cout << "x is:" << x << endl;
   cout << "y is:" << y << endl;
			cout << "Perimeter is: " << perimeter; 
		} 
	
}; 

// main function 
int main() 
{ 
	// creating object of the class 
	Rectangle obj; 
	
	// trying to access private data member 
	// directly outside the class 
	obj.compute_perimeter(5, 10); 
	
	
	return 0; 
}  
```
Output:
```
x is:5
y is:10
Perimeter is: 30
```
* **Protected**: Protected access modifier is similar to that of private access modifiers, the difference is that the class member declared as Protected are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.

``` c++
// C++ program to demonstrate 
// protected access modifier 
#include <bits/stdc++.h> 
using namespace std; 

// base class 
class Fruit 
{ 
	// protected data members 
	protected: 
	string color_protected; 
	
}; 

// sub class or derived class 
class Apple : public Fruit 
{ 
	
	
	public: 
	void setColor(string color) 
	{ 
		
		// Child class is able to access the inherited 
		// protected data members of base class 
		
		color_protected = color; 
		
	} 
	
	void displayColor() 
	{ 
		cout << "color_protected is:" << color_protected << endl; 
	} 
}; 

// main function 
int main() { 
	
	Apple obj1; 
	
	// member function of derived class can 
	// access the protected data members of base class 
	
	obj1.setColor(" green"); 
	obj1.displayColor(); 
	return 0; 
} 

```
Output:
```
color_protected is: green
```
