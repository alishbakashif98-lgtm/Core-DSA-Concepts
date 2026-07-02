/*
Program Name: Structures Basics in C/C++

Definition:
A structure is a user-defined data type that allows us to group 
multiple items of different data types under a single name.

Description:
This program demonstrates how to define a structure, declare structure 
variables, initialize them, and access their members using the dot (.) operator.
*/

#include <iostream>
using namespace std;

// 1. Defining a structure for a Rectangle
struct Rectangle {
    int length;   // 4 bytes
    int breadth;  // 4 bytes
};

int main() {
    // 2. Declaration and Initialization of a structure variable
    struct Rectangle r1 = {10, 5};
    
    // 3. Accessing and printing members using dot (.) operator
    cout << "Initial Length: " << r1.length << endl;
    cout << "Initial Breadth: " << r1.breadth << endl;
    
    // 4. Modifying values
    r1.length = 15;
    r1.breadth = 8;
    
    cout << "\n--- After Modifying Values ---" << endl;
    cout << "New Length: " << r1.length << endl;
    cout << "New Breadth: " << r1.breadth << endl;

    // 5. Size of structure variable
    cout << "\nTotal size of structure r1: " << sizeof(r1) << " bytes" << endl;

    return 0;
}