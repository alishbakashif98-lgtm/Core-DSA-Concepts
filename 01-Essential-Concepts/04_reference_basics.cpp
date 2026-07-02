/*
Program Name: Reference Basics in C++

Definition:
A reference is an alias (another name) for an existing variable. 
It does not occupy its own memory space; it shares the same memory 
location as the original variable.

Description:
This program demonstrates how to declare and initialize a reference 
variable using the ampersand (&) operator on the left-hand side, and 
shows that modifying the reference changes the original variable.
*/

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    
    // 1. Reference declaration and initialization
    // 'r' is now an alias (nickname) for 'a'
    int &r = a; 
    
    // 2. Printing values and addresses to show they are identical
    cout << "Value of a: " << a << endl;
    cout << "Value of r: " << r << endl;
    
    cout << "Address of a: " << &a << endl;
    cout << "Address of r: " << &r << endl;
    
    cout << "\n--- Modifying value through Reference ---" << endl;
    // 3. Modifying data via reference
    r = 25;
    
    cout << "New value of a: " << a << endl;
    cout << "New value of r: " << r << endl;

    return 0;
}