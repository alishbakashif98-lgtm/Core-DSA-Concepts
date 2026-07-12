/*
Program Name: Taylor Series (e^x) using Recursion

Description:
This program calculates the value of e^x using Taylor Series expansion:
e^x = 1 + x/1! + x^2/2! + x^3/3! + ... up to n terms.
It utilizes static variables to preserve the power and factorial values 
during the returning phase of recursion.
*/

#include <iostream>
using namespace std;

double taylor(int x, int n) {
    static double p = 1; // Stores the power of x (numerator)
    static double f = 1; // Stores the factorial values (denominator)
    double r;

    // Base Case: 0th term is always 1
    if (n == 0) {
        return 1;
    }

    // Recursive Call (Going down towards base case)
    r = taylor(x, n - 1);

    // Returning Time Operations (Coming back up)
    p = p * x;     // Updating power of x
    f = f * n;     // Updating factorial value
    
    return r + (p / f); // Adding current term to the sum of previous terms
}

int main() {
    int x = 1; // Power of e (i.e., e^1)
    int n = 10; // Precision level (Number of terms)
    
    cout << "--- Taylor Series (e^x) Expansion ---" << endl;
    cout << "Value of e^" << x << " with " << n << " terms is: " << taylor(x, n) << endl;
    
    return 0;
}