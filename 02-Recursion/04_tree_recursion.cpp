/*
Program Name: Tree Recursion

Definition:
If a recursive function calls itself more than once inside its body, 
it is known as Tree Recursion. The execution flow branches out like a tree.

Description:
This program demonstrates a classic tree recursion pattern where a single 
call to fun(3) triggers multiple internal branching calls.
*/

#include <iostream>
using namespace std;

void fun(int n) {
    if(n > 0) {
        cout << n << " ";  // Action at calling time
        fun(n - 1);        // First Recursive Call
        fun(n - 1);        // Second Recursive Call
    }
}

int main() {
    int x = 3;
    cout << "--- Tree Recursion Output ---" << endl;
    fun(x);
    cout << endl;
    return 0;
}