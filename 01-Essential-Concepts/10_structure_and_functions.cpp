/*
Program Name: Structure and Functions in C/C++

Definition:
Structure and Functions is a procedural programming style where a structure 
holds the data members, and separate functions are written to perform 
operations on that structure by taking it as a parameter.

Description:
This program modularizes the Rectangle logic by creating initializing, 
area-calculating, and change-length functions outside the main block.
*/

#include <iostream>
using namespace std;

// 1. Defining the structure (Data)
struct Rectangle {
    int length;
    int breadth;
};

// 2. Function to initialize the structure members (Pass by Address)
void initialize(struct Rectangle *r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

// 3. Function to calculate area (Pass by Value because we only read data)
int area(struct Rectangle r) {
    return r.length * r.breadth;
}

// 4. Function to change length dynamically (Pass by Address)
void changeLength(struct Rectangle *r, int newLength) {
    r->length = newLength;
}

int main() {
    struct Rectangle r;
    
    cout << "--- Initializing Rectangle ---" << endl;
    // Initializing length=10, breadth=5 using function
    initialize(&r, 10, 5);
    cout << "Length: " << r.length << ", Breadth: " << r.breadth << endl;
    
    // Calculating area
    int a = area(r);
    cout << "Area of Rectangle: " << a << endl;
    
    cout << "\n--- Modifying Length via Function ---" << endl;
    // Changing length to 15
    changeLength(&r, 15);
    cout << "New Length: " << r.length << endl;
    
    // Recalculating area
    cout << "New Area of Rectangle: " << area(r) << endl;

    return 0;
}