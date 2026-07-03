/*
Program Name: Parameter Passing Methods in C/C++

Description:
This program demonstrates the three types of parameter passing methods:
1. Pass by Value (Creates a copy, original values do not change)
2. Pass by Address (Uses pointers, original values change)
3. Pass by Reference (Uses aliases in C++, original values change)
*/

#include <iostream>
using namespace std;

// 1. Pass by Value
void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. Pass by Address (Pointers)
void swapByAddress(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Pass by Reference (C++ only)
void swapByReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10, b = 20;

    cout << "--- Initial Values ---" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    // Testing Pass by Value
    swapByValue(a, b);
    cout << "\n--- After swapByValue ---" << endl;
    cout << "a = " << a << ", b = " << b << " (No change)" << endl;

    // Testing Pass by Address
    swapByAddress(&a, &b); // Sending addresses
    cout << "\n--- After swapByAddress ---" << endl;
    cout << "a = " << a << ", b = " << b << " (Values Swapped!)" << endl;

    // Resetting values for next test
    a = 10; b = 20;

    // Testing Pass by Reference
    swapByReference(a, b);
    cout << "\n--- After swapByReference ---" << endl;
    cout << "a = " << a << ", b = " << b << " (Values Swapped!)" << endl;

    return 0;
}