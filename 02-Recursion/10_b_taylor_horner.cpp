/*
Program Name: Taylor Series using Horner's Rule (Iterative & Recursive)

Technical Terms & Concepts:
1. Horner's Rule: A mathematical technique used to reduce the number of multiplications 
   in a polynomial expression by taking common factors out.
2. Memoization Concept: Reducing redundant arithmetic operations by optimizing the expression 
   structure, changing time complexity from O(n^2) to O(n).
*/

#include <iostream>
using namespace std;

// Recursive Implementation of Horner's Rule
double taylorHorner(int x, int n) {
    static double s = 1; // Accumulator variable to hold the memoized sum
    
    // Base Case
    if (n == 0) {
        return s;
    }
    
    // Horner's structural modification: s = 1 + x/n * s
    s = 1 + (double)x / n * s;
    
    return taylorHorner(x, n - 1); // Linear recursive execution
}


int main() {
    int x = 1;
    int n = 10;
    
    cout << "--- Taylor Series via Horner's Rule ---" << endl;
    cout << "Optimized e^" << x << " value: " << taylorHorner(x, n) << endl;
    
    return 0;
}