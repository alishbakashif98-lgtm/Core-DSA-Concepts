/*
Program Name: Introduction to Recursion

Definition:
A function that calls itself directly or indirectly is called a recursive function. 
It must have a base case to terminate, otherwise it will run infinitely and cause a Stack Overflow.

Description:
This program demonstrates a basic recursive function that prints numbers from n down to 1.
*/

#include <iostream>
using namespace std;

void fun(int n) {
    if(n > 0) { // Base Case / Controlling Condition
        cout << n << " "; // 1. Calling Time Action (Ascending/Descending phase)
        fun(n - 1);       // 2. Recursive Call to itself
    }
}

int main() {
    int x = 3;
    cout << "--- Recursion Output ---" << endl;
    fun(x); // Calling the recursive function
    cout << endl;
    return 0;
}