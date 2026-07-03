/*
Program Name: Structure as Parameter in C/C++

Description:
This program demonstrates how to pass a structure to a function using:
1. Pass by Value (Creates a copy, original structure remains unchanged)
2. Pass by Address (Passes pointer, allows modification of original structure)
3. Pass by Reference (C++ only, works as an alias)
*/

#include <iostream>
using namespace std;

// Defining a structure
struct Rectangle {
    int length;
    int breadth;
};

// 1. Pass by Value
// This takes a separate copy, so changes here won't affect main()
void changeLengthValue(struct Rectangle r) {
    r.length = 20;
    cout << "Inside changeLengthValue (Copy): " << r.length << endl;
}

// 2. Pass by Address
// This takes a pointer, so changes here WILL affect main()
void changeLengthAddress(struct Rectangle *p) {
    p->length = 30; // Using arrow operator to modify original object
    cout << "Inside changeLengthAddress (Original): " << p->length << endl;
}

// 3. Pass by Reference (C++ only)
// This takes an alias, so changes here WILL affect main()
void changeLengthReference(struct Rectangle &rRef) {
    rRef.length = 50; // Using dot operator on reference
    cout << "Inside changeLengthReference (Original): " << rRef.length << endl;
}

int main() {
    struct Rectangle r = {10, 5};
    
    cout << "--- Initial Value in main ---" << endl;
    cout << "Original Length: " << r.length << ", Breadth: " << r.breadth << endl;

    // Test 1: Pass by Value
    cout << "\n--- Testing Pass by Value ---" << endl;
    changeLengthValue(r);
    cout << "Value in main after function call: " << r.length << " (Unchanged)" << endl;

    // Test 2: Pass by Address
    cout << "\n--- Testing Pass by Address ---" << endl;
    changeLengthAddress(&r); // Passing address using &
    cout << "Value in main after function call: " << r.length << " (Changed!)" << endl;

    // Test 3: Pass by Reference
    cout << "\n--- Testing Pass by Reference ---" << endl;
    changeLengthReference(r); // Passing normally as reference
    cout << "Value in main after function call: " << r.length << " (Changed!)" << endl;

    return 0;
}