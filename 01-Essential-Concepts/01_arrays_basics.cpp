/*
Program Name: Arrays Basics in C++

Definition:
An array is a collection of contiguous memory locations that store 
multiple elements of the same data type under a single variable name.

Description:
This program demonstrates how to declare, initialize, and traverse 
a static array in C++. It also shows how to access individual elements 
using indexes and how to initialize an array with garbage values or zeros.
*/

#include <iostream>
using namespace std;

int main() {
    // 1. Declaration and Initialization
    int A[5] = {2, 4, 6, 8, 10};
    
    // 2. Accessing elements using index
    cout << "Element at index 0: " << A[0] << endl;
    cout << "Element at index 2: " << A[2] << endl;
    
    cout << "\n--- Printing all elements using for loop ---" << endl;
    // 3. Traversing the array using a normal for loop
    for(int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    cout << "\n--- Printing using For-Each loop (C++11) ---" << endl;
    // 4. Modern C++ For-Each loop
    for(int x : A) {
        cout << x << " ";
    }
    cout << endl;

    // 5. Array size concept
    cout << "\nTotal size of array A in memory: " << sizeof(A) << " bytes" << endl;

    return 0;
}