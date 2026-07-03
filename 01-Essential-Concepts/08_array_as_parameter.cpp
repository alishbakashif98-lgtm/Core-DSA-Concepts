/*
Program Name: Array as Parameter in C/C++

Definition:
Passing an array to a function means passing the base address (address of the 0th index) 
of the array to a pointer parameter in the function.

Description:
This program demonstrates how to pass an array to a function, why arrays are 
always passed by address, and how to dynamically allocate an array inside a function 
and return its pointer to the main function.
*/

#include <iostream>
using namespace std;

// 1. Function to print an array (Takes array pointer and its size)
// int A[] is internally treated as int *A
void printArray(int A[], int size) {
    cout << "Printing elements inside function: ";
    for(int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// 2. Function that returns a pointer to a dynamically allocated array
int* createArray(int size) {
    int *p;
    p = new int[size]; // Dynamically allocating memory in Heap (C++)
    
    // Initializing the dynamic array
    for(int i = 0; i < size; i++) {
        p[i] = (i + 1) * 10;
    }
    return p; // Returning the address of heap memory
}

int main() {
    // Test 1: Passing a static array to a function
    int myArr[] = {2, 4, 6, 8, 10};
    int n = 5;
    
    cout << "--- Test 1: Passing Static Array ---" << endl;
    printArray(myArr, n); // Passing array name (which is the base address)

    // Test 2: Receiving dynamically created array from a function
    cout << "\n--- Test 2: Returning Array from Function ---" << endl;
    int *dynamicArr;
    int size = 5;
    
    dynamicArr = createArray(size); // Getting pointer from function
    
    cout << "Printing dynamic array elements in main: ";
    for(int i = 0; i < size; i++) {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;

    // Freeing the dynamically allocated memory
    delete [] dynamicArr;

    return 0;
}