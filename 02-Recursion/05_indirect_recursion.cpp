/*
Program Name: Indirect Recursion

Definition:
In Indirect Recursion, multiple functions call each other in a circular 
cycle or chain (e.g., Function A calls Function B, and Function B calls Function A).

Description:
This program demonstrates mutual recursion between funA and funB where 
funA divides the value by 2 and funB decrements it by 1.
*/

#include <iostream>
using namespace std;

// Forward declaration of funB so that funA knows it exists
void funB(int n);

// Function A
void funA(int n) {
    if(n > 0) {
        cout << n << " ";
        funB(n - 1); // funA calls funB
    }
}

// Function B
void funB(int n) {
    if(n > 1) {
        cout << n << " ";
        funA(n / 2); // funB calls funA back by dividing n by 2
    }
}

int main() {
    int x = 20;
    cout << "--- Indirect Recursion Output ---" << endl;
    funA(x);
    cout << endl;
    return 0;
}