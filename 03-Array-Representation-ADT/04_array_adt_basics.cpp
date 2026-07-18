/*
Program Name: Array ADT - Structure Initialization, Display, and Append Operations

Important Terms & Critical Concepts (Master Notes):
1. Array ADT (Abstract Data Type): A mathematical model for data types where the data type 
   is defined by its behavior (operations) rather than its implementation.
2. Data Members Layout:
   - Pointer (*A): Points directly to the contiguous address block allocated in Heap memory.
   - Size: The total allocated capacity of the array (Maximum items it can hold).
   - Length: The actual number of elements present at the current moment (Always: Length <= Size).
3. C vs C++ Structural Shift:
   - In C, data and functions are separated; we pass a struct pointer (e.g., &arr) to every function.
   - In C++, Object-Oriented Programming (OOP) wraps data and functions into a single 'class'.
   - Malloc vs New: C uses `malloc(sz * sizeof(int))`, C++ uses the cleaner `new int[sz]` operator.
   - Destructors (~Array): Automatically triggers memory deallocation via `delete[]`, completely 
     eliminating manual memory management and preventing memory leaks.
4. Operations Breakdown:
   - Display(): Traverses from index 0 to length-1 to print items. Time Complexity: O(n).
   - Append(x): Inserts element 'x' directly at the end (index = length). Time Complexity: O(1).
     Edge Case: Can only append if Length < Size; otherwise, the array is full.
*/

#include <iostream>
using namespace std;

class Array {
private:
    int *A;      // Pointer to dynamic array in Heap
    int size;    // Total capacity
    int length;  // Current number of elements

public:
    // Parameterized Constructor (Dynamic Initialization)
    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size]; // Allocating memory in heap
    }

    // Destructor (Automatic Memory Cleanup)
    ~Array() {
        delete []A; 
        cout << "\n[System Note] Heap memory allocated for array has been safely released." << endl;
    }

    // 1. Display Operation - Time Complexity: O(n)
    void Display() {
        cout << "Elements are: ";
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    // 2. Append Operation - Time Complexity: O(1)
    void Append(int x) {
        // Edge Case Check: Ensure space is available
        if (length < size) {
            A[length] = x; // Place item at the available index
            length++;      // Increment length counter
        } else {
            cout << "Append Error: Array is full! Cannot add " << x << endl;
        }
    }

    // Helper method to set manual items for initial validation
    void SetLength(int l) {
        if (l <= size) length = l;
    }
    int* GetArrayPointer() { return A; }
};

int main() {
    int max_capacity = 10;
    
    // Initializing the Array ADT Class object
    Array arr(max_capacity);
    
    cout << "--- Array ADT Basics: Display & Append ---" << endl;
    
    // Manually injecting a few elements for the initial showcase
    int *ptr = arr.GetArrayPointer();
    ptr[0] = 12; ptr[1] = 15; ptr[2] = 25;
    arr.SetLength(3);
    
    // Display initial array state
    arr.Display();
    
    // Performing Appends
    cout << "\nAppending 45 to the array..." << endl;
    arr.Append(45);
    arr.Display();
    
    cout << "\nAppending 70 to the array..." << endl;
    arr.Append(70);
    arr.Display();
    
    return 0;
}