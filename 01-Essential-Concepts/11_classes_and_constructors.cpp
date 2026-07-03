/*
Program Name: C++ Classes and Constructors

Definition:
A class is a blueprint or template that encapsulates data members 
and member functions into a single entity. An object is an instance of a class.

Description:
This program converts the procedural Rectangle code into a complete 
Object-Oriented program using a class, access specifiers, and a constructor.
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    // Data Members (Hidden from outside world for security/encapsulation)
    int length;
    int breadth;

public:
    // 1. Parameterized Constructor
    // Automatically runs when an object is created to initialize data
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    // 2. Member Function to calculate area
    int area() {
        return length * breadth;
    }

    // 3. Member Function to change length (Mutator)
    void changeLength(int newLength) {
        length = newLength;
    }

    // 4. Getter function to read length (Accessor)
    int getLength() {
        return length;
    }
};

int main() {
    cout << "--- Creating Object & Automatic Initialization via Constructor ---" << endl;
    // Creating object 'r' and passing initial values directly
    Rectangle r(10, 5); 
    
    // Calculating area
    cout << "Initial Area: " << r.area() << endl;
    
    cout << "\n--- Modifying Data via Member Function ---" << endl;
    // Changing length using the class function
    r.changeLength(15);
    cout << "New Length: " << r.getLength() << endl;
    
    // Recalculating area
    cout << "New Area: " << r.area() << endl;

    return 0;
}