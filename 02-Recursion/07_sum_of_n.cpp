/*
Program Name: Sum of First N Natural Numbers using Recursion

Description:
This program calculates the sum of first N natural numbers (e.g., 1 + 2 + 3 + ... + N) 
using three different approaches:
1. Recursive Approach
2. Iterative (Loop) Approach
3. Constant Time Formula Approach [n * (n + 1) / 2]
*/

#include <iostream>
using namespace std;

// 1. Recursive Method
int sumRecursive(int n) {
    if (n == 0) {
        return 0; // Base Case
    } else {
        return sumRecursive(n - 1) + n; // Recursive case (Returning time addition)
    }
}

// 2. Iterative Method (Loop)
int sumIterative(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = s + i;
    }
    return s;
}

// 3. Formula Method
int sumFormula(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int num = 5;
    
    cout << "--- Sum of First " << num << " Natural Numbers ---" << endl;
    cout << "Using Recursion: " << sumRecursive(num) << endl;
    cout << "Using Loop:      " << sumIterative(num) << endl;
    cout << "Using Formula:   " << sumFormula(num) << endl;
    
    return 0;
}