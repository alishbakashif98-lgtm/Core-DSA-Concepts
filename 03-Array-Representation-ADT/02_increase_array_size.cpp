/*
Program Name: Increasing Array Size Dynamic Demonstration

Technical Terms & Concepts:
1. Dynamic Resizing: Changing the capacity of a heap-allocated array by creating a 
   larger array, copying elements, reassigning the pointer, and deleting the old memory.
2. Memory Leak Prevention: Deallocating the smaller original array using `delete[]` 
   before shifting pointers to avoid orphaned memory.
*/

#include <iostream>
using namespace std;

int main() {
    // 1. Create a small array in heap
    int *p = new int[5]{2, 4, 6, 8, 10};
    
    // 2. Create a larger array in heap to host expanded elements
    int *q = new int[10];
    
    // 3. Copy elements from older array to new array
    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }
    
    // 4. Free the old memory block to prevent memory leaks
    delete []p;
    
    // 5. Shift pointer 'p' to point to the larger array 'q'
    p = q;
    q = nullptr; // Clear temporary pointer
    
    // Verify the expanded array
    cout << "--- Expanded Heap Array Elements ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }
    cout << "\nArray size successfully increased dynamically!" << endl;
    
    delete []p; // Final cleanup
    return 0;
}