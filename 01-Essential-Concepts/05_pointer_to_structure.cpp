/*
Program Name: Pointer to Structure in C/C++

Definition:
A pointer to a structure is a pointer variable that holds the memory 
address of a structure variable, allowing us to access and manipulate 
its members dynamically.

Description:
This program demonstrates how to declare a pointer to a structure, 
initialize it, and access the structure's members using both the 
traditional dereferencing method and the arrow (->) operator.
*/

#include <iostream>
using namespace std;

// Defining a structure
struct Rectangle {
    int length;
    int breadth;
};

int main() {
    // 1. Creating a normal structure variable
    struct Rectangle r = {10, 5};
    
    // 2. Creating a structure pointer and assigning address of 'r'
    struct Rectangle *p = &r;
    
    // 3. Accessing members using normal variable (Dot operator)
    cout << "Using Object (Dot Operator):" << endl;
    cout << "Length: " << r.length << endl;
    cout << "Breadth: " << r.breadth << endl;
    
    cout << "\nUsing Pointer (Arrow Operator):" << endl;
    // 4. Accessing members using pointer (Arrow '->' operator)
    // p->length is a shorthand for (*p).length
    cout << "Length via Pointer: " << p->length << endl;
    cout << "Breadth via Pointer: " << p->breadth << endl;
    
    // 5. Modifying values using pointer
    p->length = 20;
    p->breadth = 15;
    
    cout << "\n--- After Modifying via Pointer ---" << endl;
    cout << "New Length: " << r.length << endl;
    cout << "New Breadth: " << r.breadth << endl;

    return 0;
}