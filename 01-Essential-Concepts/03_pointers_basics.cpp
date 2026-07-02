/*
Program Name: Pointers Basics in C/C++

Definition:
A pointer is a special variable that stores the memory address of 
another variable rather than storing a direct value.

Description:
This program demonstrates how to declare a pointer, initialize it with 
the address of a variable using the ampersand (&) operator, and access/modify 
the data using the dereferencing (*) operator.
*/

#include <iostream>
using namespace std;

int main() {
    // 1. Data variable declaration
    int a = 10;
    
    // 2. Pointer declaration and initialization
    int *p;      // Declaration of pointer
    p = &a;      // Storing the address of variable 'a' in pointer 'p'
    
    // 3. Printing values and addresses
    cout << "Value of a: " << a << endl;
    cout << "Address of a (&a): " << &a << endl;
    cout << "Value stored in pointer p (Address of a): " << p << endl;
    cout << "Address of pointer p itself (&p): " << &p << endl;
    
    cout << "\n--- Dereferencing the Pointer ---" << endl;
    // 4. Accessing the value using dereferencing (*) operator
    cout << "Value pointed by p (*p): " << *p << endl;
    
    // 5. Modifying value via pointer
    *p = 20; 
    cout << "\n--- After Modifying Value via Pointer ---" << endl;
    cout << "New value of a: " << a << endl;
    cout << "Value pointed by p (*p): " << *p << endl;

    return 0;
}