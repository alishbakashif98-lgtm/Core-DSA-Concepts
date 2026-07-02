/*
Program Name: Functions Basics in C/C++

Definition:
A function is a sub-program or a block of code designed to perform 
a specific, reusable task.

Description:
This program demonstrates how to define a function with parameters, 
call it from the main() function, and understand how execution 
control transfers between the caller and the called function.
*/

#include <iostream>
using namespace std;

// 1. Function Definition
// This function takes two integers as parameters and returns their sum
int add(int num1, int num2) {
    int sum;
    sum = num1 + num2;
    return sum; // Returning the result back to the caller
}

int main() {
    int a = 10;
    int b = 20;
    int c;
    
    // 2. Function Call
    // Control transfers to add() function, carrying values of 'a' and 'b'
    c = add(a, b);
    
    // 3. Printing the result
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Sum (Result from function): " << c << endl;

    return 0;
}