/*
Program Name: Nested Recursion

Definition:
In Nested Recursion, a recursive function passes a recursive call to itself 
as a parameter (i.e., a function inside a function call like fun(fun(n + 1))).

Description:
This program demonstrates nested recursion using a classic mathematical function 
logic (similar to the famous Ackermann or McCarty 91 function logic) where 
values greater than 100 reduce, and values less than or equal to 100 trigger a nest.
*/

#include <iostream>
using namespace std;

int fun(int n) {
    if(n > 100) {
        return n - 10; // Base condition/termination rule
    } else {
        return fun(fun(n + 11)); // Nested recursive call
    }
}

int main() {
    int r;
    r = fun(95);
    cout << "--- Nested Recursion Output ---" << endl;
    cout << "Result of fun(95): " << r << endl;
    return 0;
}