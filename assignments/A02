/*
  description: This program creates two lists and pushes values onto it. The values in the first two lists are
  pushed using a for loop while the third list is created by concatinating the values in the lhs(the first list) and the rhs(the second list). It does this by looping through the two lists and pushing the values onto the new list. It prints the last value in the first and the second list, prints out the concatinated third list, and prints the value in the fifth index of the third list.
*/



#include <iostream>

using namespace std;

int A[100];

// creates node with next as a pointer
struct Node
{
    int x;
    Node *next;
    
    // node contructor if no value is passed in
    Node()
    {
        x = -1;
        next = NULL;
    }
    // constructor with a value passed in for parameter
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

// a list that holds values. 
class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
      // prints the tail of a list
    void PrintTail()
    {
        cout << Tail->x << endl;
    }

    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented 
    int Pop()
    {
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

          // checks if the index is greater than the size if it is then the program terminates
        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }
      // friend allows access to private members of the class
    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;
    List L2;

    // pushes values onto the first list
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }
    // pushes values onto the second list
    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;

    // prints the last value in the first list
    L1.PrintTail();
    // prints the last value in the second list
    L2.PrintTail();

    // concatinates list one and two to a third list and prints it out
    List L3 = L1 + L2;
    cout << L3 << endl;

    // prints the value in the fifth index of the third list
    cout << L3[5] << endl;
    return 0;
}
