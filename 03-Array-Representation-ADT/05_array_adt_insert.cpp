/*
Program Name: Array ADT - Insert Operation with Index Validation and Shifting Mechanics

Important Terms & Critical Concepts (Master Notes):
1. Insert(index, x): Inserts a new element 'x' at a specific target position/index. 
   Unlike Append (which just places an item at the end), Insert forces existing elements to shift.
2. Index Shifting Logic (The Core Mechanic):
   - To insert at an index 'i', all elements from that index up to 'length-1' must move one step to the right.
   - Crucial Rule: Shifting must ALWAYS start from the back (from index = length down to index > target). 
     If you start shifting from the front, you will overwrite and destroy your own data!
3. Edge Cases & Boundary Conditions:
   - Array Full Check: If length == size, there is no physical space left to shift elements. The operation must abort.
   - Index Validity Check: The target index must be >= 0 AND it must be <= length. 
     Note: Inserting at index == length is perfectly valid (it simply behaves exactly like an Append operation).
4. Time Complexity Analytics:
   - Best Case: O(1) -> If you insert at the very end (index = length), zero elements need to be shifted.
   - Worst Case: O(n) -> If you insert at the very beginning (index = 0), every single element in the array must shift.
   - Average Case: O(n) -> On average, you will shift n/2 elements, which simplifies to linear time O(n).
*/

#include <iostream>
using namespace std;

class Array {
private:
    int *A;      // Pointer to dynamic array in Heap
    int size;    // Total capacity
    int length;  // Current number of elements

public:
    // Constructor
    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size];
    }

    // Destructor
    ~Array() {
        delete []A;
    }

    // Display Method
    void Display() {
        cout << "Current Elements: ";
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    // --- THE INSERT OPERATION ---
    void Insert(int index, int x) {
        // Edge Case 1: Check if there is space in the array
        if (length >= size) {
            cout << "Insert Error: Array capacity full! Cannot insert " << x << endl;
            return;
        }

        // Edge Case 2: Check if the provided index is valid and reachable
        if (index >= 0 && index <= length) {
            // Shifting elements to the right starting from the back
            for (int i = length; i > index; i--) {
                A[i] = A[i - 1];
            }
            
            A[index] = x; // Safely place the new item in the vacant slot
            length++;     // Expand the actual length counter
            cout << "Successfully inserted " << x << " at index " << index << endl;
        } else {
            cout << "Insert Error: Invalid Index " << index << " (Out of bounds)!" << endl;
        }
    }

    // Helper methods to set up initial data
    void SetInitialData() {
        A[0] = 10; A[1] = 20; A[2] = 30; A[3] = 40;
        length = 4;
    }
};

int main() {
    Array arr(10); // Creating an array with maximum capacity of 10
    arr.SetInitialData(); // Initial array: [10, 20, 30, 40] (length = 4)
    
    cout << "--- Array ADT: Insert Operation Showcase ---" << endl;
    arr.Display();
    
    // Test Case 1: Valid Insertion in the middle
    cout << "\n[Test 1] Inserting 25 at index 2..." << endl;
    arr.Insert(2, 25);
    arr.Display();
    
    // Test Case 2: Valid Insertion at the boundary (Acts like Append)
    cout << "\n[Test 2] Inserting 50 at index 5 (current length)..." << endl;
    arr.Insert(5, 50);
    arr.Display();
    
    // Test Case 3: Invalid Insertion (Out of bounds)
    cout << "\n[Test 3] Attempting to insert 99 at an unreachable index 8..." << endl;
    arr.Insert(8, 99);
    arr.Display();
    
    return 0;
}