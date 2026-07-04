/*
Program Name: Static and Global Variables in Recursion

Description:
This program demonstrates how static (or global) variables behave inside 
a recursive function. Unlike normal local variables, static variables are 
allocated memory only once, and their value persists across recursive calls.
*/

#include <iostream>
using namespace std;

// 1. Function using normal Local Variable
int funWithLocal(int n) {
    if(n > 0) {
        return funWithLocal(n - 1) + n; // Uses local 'n' at returning time
    }
    return 0;
}

// 2. Function using a Static Variable
int funWithStatic(int n) {
    static int x = 0; // Allocated once in the data section, NOT on stack
    if(n > 0) {
        x++; // Increments at calling time
        return funWithStatic(n - 1) + x; // Uses modified 'x' at returning time
    }
    return 0;
}

int main() {
    int a = 5;
    
    cout << "--- Using Normal Local Variable ---" << endl;
    cout << "Result for funWithLocal(5): " << funWithLocal(a) << endl;
    
    cout << "\n--- Using Static Variable ---" << endl;
    cout << "Result for funWithStatic(5): " << funWithStatic(a) << endl;
    
    return 0;
}