/*
Program Name: Factorial of a Number using Recursion

Description:
This program calculates the factorial of a given number (e.g., 5! = 5 * 4 * 3 * 2 * 1 = 120)
using two approaches:
1. Recursive Approach
2. Iterative (Loop) Approach
*/

#include <iostream>
using namespace std;

// 1. Recursive Method
int factRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base Case: 0! and 1! are both 1
    } else {
        return factRecursive(n - 1) * n; // Recursive case (Returning time multiplication)
    }
}

// 2. Iterative Method (Loop)
int factIterative(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f = f * i;
    }
    return f;
}

int main() {
    int num = 5;
    
    cout << "--- Factorial of " << num << " ---" << endl;
    cout << "Using Recursion: " << factRecursive(num) << endl;
    cout << "Using Loop:      " << factIterative(num) << endl;
    
    return 0;
}