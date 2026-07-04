/*
Program Name: Head and Tail Recursion

Description:
This program demonstrates the difference between:
1. Tail Recursion: The recursive call is the last statement. All operations happen at calling time.
2. Head Recursion: The recursive call is the first statement. All operations happen at returning time.
*/

#include <iostream>
using namespace std;

// 1. Tail Recursion Function
void tailFunction(int n) {
    if(n > 0) {
        cout << n << " ";     // Action performed at Calling Time
        tailFunction(n - 1);  // Recursive call is at the absolute end (Tail)
    }
}

// 2. Head Recursion Function
void headFunction(int n) {
    if(n > 0) {
        headFunction(n - 1);  // Recursive call is at the beginning (Head)
        cout << n << " ";     // Action performed at Returning Time
    }
}

int main() {
    int x = 3;
    
    cout << "--- Tail Recursion Output (Descending) ---" << endl;
    tailFunction(x); 
    cout << endl;
    
    cout << "\n--- Head Recursion Output (Ascending) ---" << endl;
    headFunction(x); 
    cout << endl;
    
    return 0;
}