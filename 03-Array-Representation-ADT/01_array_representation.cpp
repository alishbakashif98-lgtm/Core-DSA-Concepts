/*
Program Name: Array Representation (Static vs Dynamic Memory Allocation)

Technical Terms & Concepts:
1. Static Array: Allocated inside the Stack memory. Size is fixed at compile-time 
   and cannot be changed during runtime.
2. Dynamic Array: Allocated inside the Heap memory using pointers (`new` in C++). 
   Allows creation of arrays whose size can be decided at runtime.
*/

#include <iostream>
using namespace std;

int main() {
    // 1. Static Array Allocation (Stack Memory)
    int A[5] = {2, 4, 6, 8, 10};
    
    // 2. Dynamic Array Allocation (Heap Memory)
    int *P;
    P = new int[5]; // Allocating memory in Heap
    P[0] = 3;
    P[1] = 5;
    P[2] = 7;
    P[3] = 9;
    P[4] = 11;
    
    cout << "--- Stack Array (Static) Elements ---" << endl;
    for(int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    cout << "\n--- Heap Array (Dynamic) Elements ---" << endl;
    for(int i = 0; i < 5; i++) {
        cout << P[i] << " ";
    }
    cout << endl;
    
    // Deallocating Heap memory to prevent memory leaks
    delete []P;
    
    return 0;
} 