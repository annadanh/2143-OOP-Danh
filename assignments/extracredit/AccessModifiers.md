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
filter_none
edit
play_arrow

brightness_4
// C++ program to demonstrate public 
// access modifier 
``` c++  
#include<iostream> 
using namespace std; 
  
// class definition 
class Circle 
{ 
    public:  
        double radius; 
          
        double  compute_area() 
        { 
            return 3.14*radius*radius; 
        } 
      
}; 
  
// main function 
int main() 
{ 
    Circle obj; 
      
    // accessing public datamember outside class 
    obj.radius = 5.5; 
      
    cout << "Radius is:" << obj.radius << "\n"; 
    cout << "Area is:" << obj.compute_area(); 
    return 0; 
} 
```
Output:

Radius is:5.5
Area is:94.985
In the above program the data member radius is public so we are allowed to access it outside the class.

**Private**: The class members declared as **private** can be accessed only by the functions inside the class. They are not allowed to be accessed directly by any object or function outside the class. Only the member functions or the friend functions are allowed to access the private data members of a class.
Example:

 

filter_none
edit
play_arrow

brightness_4
// C++ program to demonstrate private 
// access modifier 
``` c++
#include<iostream> 
using namespace std; 
  
class Circle 
{    
    // private data member 
    private:  
        double radius; 
       
    // public member function     
    public:     
        double  compute_area() 
        {   // member function can access private  
            // data member radius 
            return 3.14*radius*radius; 
        } 
      
}; 
  
// main function 
int main() 
{    
    // creating object of the class 
    Circle obj; 
      
    // trying to access private data member 
    // directly outside the class 
    obj.radius = 1.5; 
      
    cout << "Area is:" << obj.compute_area(); 
    return 0; 
} 
```
The output of above program will be a compile time error because we are not allowed to access the private data members of a class directly outside the class.
Output:

 In function 'int main()':
11:16: error: 'double Circle::radius' is private
         double radius;
                ^
31:9: error: within this context
     obj.radius = 1.5;
         ^
However we can access the private data members of a class indirectly using the public member functions of the class. Below program explains how to do this:

filter_none
edit
play_arrow

brightness_4
// C++ program to demonstrate private 
// access modifier 
``` c++  
#include<iostream> 
using namespace std; 
  
class Circle 
{    
    // private data member 
    private:  
        double radius; 
       
    // public member function     
    public:     
        double  compute_area(double r) 
        {   // member function can access private  
            // data member radius 
            radius = r; 
              
            double area = 3.14*radius*radius; 
              
            cout << "Radius is:" << radius << endl; 
            cout << "Area is: " << area; 
        } 
      
}; 
  
// main function 
int main() 
{    
    // creating object of the class 
    Circle obj; 
      
    // trying to access private data member 
    // directly outside the class 
    obj.compute_area(1.5); 
      
      
    return 0; 
} 
```
Output:

Radius is:1.5
Area is: 7.065

**Protected**: Protected access modifier is similar to that of private access modifiers, the difference is that the class member declared as Protected are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.
filter_none
edit
play_arrow

brightness_4
// C++ program to demonstrate 
// protected access modifier 
``` c++
#include <bits/stdc++.h> 
using namespace std; 
  
// base class 
class Parent 
{    
    // protected data members 
    protected: 
    int id_protected; 
     
}; 
  
// sub class or derived class 
class Child : public Parent 
{ 
     
      
    public: 
    void setId(int id) 
    { 
          
        // Child class is able to access the inherited  
        // protected data members of base class 
          
        id_protected = id; 
          
    } 
      
    void displayId() 
    { 
        cout << "id_protected is:" << id_protected << endl; 
    } 
}; 
  
// main function 
int main() { 
      
    Child obj1; 
      
    // member function of derived class can 
    // access the protected data members of base class 
      
    obj1.setId(81); 
    obj1.displayId(); 
    return 0; 
} 
```
Output:

id_protected is:81
