/*
Program Name: Fibonacci Series using Recursion and Memoization

Technical Terms & Concepts:
1. Excessive Recursion / Redundant Calls: A situation where a recursive function 
   recomputes the same values repeatedly, leading to exponential time complexity O(2^n).
2. Memoization (Ideal Track): An optimization technique used to speed up computer programs 
   by storing the results of expensive function calls in a global array/lookup table 
   and returning the cached result when the same inputs occur again. Reduces time to O(n).
*/

#include <iostream>
using namespace std;

// Global Array for Memoization (Acts as our memory/cache lookup table)
int F[50];

// 1. Standard Tree Recursive Method (Excessive Recursion - O(2^n))
int fibNormal(int n) {
    if (n <= 1) {
        return n; // Base Cases: fib(0)=0, fib(1)=1
    }
    return fibNormal(n - 2) + fibNormal(n - 1); // Triggers twin redundant branches
}

// 2. Optimized Recursive Method using Memoization (O(n) Time)
int fibMemo(int n) {
    if (n <= 1) {
        F[n] = n; // Store base case in memory
        return n;
    }
    else {
        // If the value is not calculated yet (contains -1)
        if (F[n - 2] == -1) {
            F[n - 2] = fibMemo(n - 2);
        }
        if (F[n - 1] == -1) {
            F[n - 1] = fibMemo(n - 1);
        }
        
        // Memoizing the calculated result before returning
        F[n] = F[n - 2] + F[n - 1];
        return F[n];
    }
}

int main() {
    int n = 7; // Finding the 7th Fibonacci term
    
    // Initializing the memoization array with -1 to represent 'unvisited/empty'
    for (int i = 0; i < 50; i++) {
        F[i] = -1;
    }
    
    cout << "--- Fibonacci Calculation (Term " << n << ") ---" << endl;
    cout << "Using Normal Tree Recursion: " << fibNormal(n) << endl;
    cout << "Using Optimized Memoization: " << fibMemo(n) << endl;
    
    return 0;
}