/*
Program Name: C++ Template Classes (Generics)

Definition:
A template class allows a class to have generic data types, meaning the 
same class logic can work with different data types (like int, float, char) 
without rewriting the code.

Description:
This program converts our Rectangle class into a Template class, demonstrating 
how to perform operations on both 'int' and 'float' data types dynamically.
*/

#include <iostream>
using namespace std;

// 1. Defining a Template Class
template <class T>
class Rectangle {
private:
    T length;  // Data type will be decided at the time of object creation
    T breadth;

public:
    // Constructor
    Rectangle(T l, T b) {
        length = l;
        breadth = b;
    }

    // Member Function to calculate area
    T area() {
        return length * breadth;
    }

    // Member Function to change length
    void changeLength(T newLength) {
        length = newLength;
    }
};

int main() {
    cout << "--- Testing Template Class with Integer ---" << endl;
    // 2. Creating an object for 'int' data type
    Rectangle<int> r1(10, 5);
    cout << "Integer Area: " << r1.area() << endl;

    cout << "\n--- Testing Template Class with Float ---" << endl;
    // 3. Creating an object for 'float' data type
    Rectangle<float> r2(10.5f, 5.2f);
    cout << "Float Area: " << r2.area() << endl;

    return 0;
}