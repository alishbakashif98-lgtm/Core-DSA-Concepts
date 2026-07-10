/*
Program Name: Power Function (m^n) using Recursion

Description:
This program calculates the power of a number (m raised to the power n) using two recursive strategies:
1. Normal Recursion: m * m^(n-1) -> Takes O(n) steps.
2. Optimized Recursion (Bari Sir's Trick): Reduces steps by halving the power -> Takes O(log n) steps.
*/

#include <iostream>
using namespace std;

// 1. Normal Recursive Method (O(n) Time Complexity)
int powerNormal(int m, int n) {
    if (n == 0) {
        return 1; // Base Case: Anything raised to power 0 is 1
    }
    return powerNormal(m, n - 1) * m;
}

// 2. Optimized Faster Recursive Method (O(log n) Time Complexity)
int powerOptimized(int m, int n) {
    if (n == 0) {
        return 1; // Base Case
    }
    
    // If power 'n' is Even
    if (n % 2 == 0) {
        return powerOptimized(m * m, n / 2);
    } 
    // If power 'n' is Odd
    else {
        return m * powerOptimized(m * m, (n - 1) / 2);
    }
}

int main() {
    int base = 2;
    int exp = 8;
    
    cout << "--- Calculating " << base << "^" << exp << " ---" << endl;
    cout << "Using Normal Recursion (Linear):    " << powerNormal(base, exp) << endl;
    cout << "Using Optimized Recursion (Faster): " << powerOptimized(base, exp) << endl;
    
    return 0;
}