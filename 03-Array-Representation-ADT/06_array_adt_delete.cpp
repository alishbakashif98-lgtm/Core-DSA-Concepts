/*
Program Name: Array ADT - Delete Operation with Left Shifting Mechanics

Important Terms & Critical Concepts (Master Notes):
1. Delete(index): Removes an element from a specific index. Arrays must always hold 
   contiguous memory blocks, so gaps are not allowed. To close the gap created by deletion, 
   all elements to the right must shift one position to the left.
2. Forward Shifting Logic (The Core Mechanic):
   - Shifting MUST start from the target 'index' moving forward to the end: A[i] = A[i + 1].
   - If you shift from back to front here, you will copy the last element onto everything.
3. Edge Cases & Boundary Conditions:
   - Index Validity Check: The target index must be greater than or equal to 0, 
     and strictly less than length (index >= 0 && index < length). You cannot delete from an empty spot!
   - Dynamic Length Shrinkage: Always decrement length (length--) after successful shifting.
4. Time Complexity Analytics:
   - Best Case: O(1) -> Deleting from the very end (index = length - 1) requires 0 shifts.
   - Worst Case: O(n) -> Deleting from the very beginning (index = 0) forces all 'n' elements to shift left.
   - Average Case: O(n) -> Requires shifting n/2 elements on average.
*/

#include <iostream>
using namespace std;

class Array {
private:
    int *A;      // Pointer to dynamic array in Heap
    int size;    // Total capacity of the array
    int length;  // Actual number of elements currently present

public:
    // Parameterized Constructor
    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size];
    }

    // Destructor to clean up heap memory automatically
    ~Array() {
        delete []A;
    }

    // Easy Display function
    void Display() {
        cout << "Current Array: ";
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    // --- THE DELETE OPERATION ---
    int Delete(int index) {
        // Edge Case: Check if index is valid and within bounds
        if (index >= 0 && index < length) {
            int deleted_value = A[index]; // 1. Take backup of the element

            // 2. Forward Shifting: Pull elements from right to left
            for (int i = index; i < length - 1; i++) {
                A[i] = A[i + 1];
            }

            length--; // 3. Reduce length counter since one element is removed
            return deleted_value; // Return the deleted value to the user
        }

        // Return -1 if index is invalid
        cout << "Delete Error: Invalid Index " << index << "!" << endl;
        return -1; 
    }

    // Helper function to fill array with mock data for testing
    void SetMockData() {
        A[0] = 10; A[1] = 20; A[2] = 30; A[3] = 40; A[4] = 50;
        length = 5;
    }
};

int main() {
    Array arr(10); // Array of size 10
    arr.SetMockData(); // Populating: [10, 20, 30, 40, 50]
    
    cout << "--- Array ADT: Easy Delete Showcase ---" << endl;
    arr.Display();
    
    // Test 1: Deleting from Index 1 (Value 20)
    cout << "\n[Test 1] Deleting element from index 1..." << endl;
    int val1 = arr.Delete(1);
    if (val1 != -1) {
        cout << "Deleted Value: " << val1 << endl;
    }
    arr.Display();
    
    // Test 2: Deleting the last element (Index 3 -> Value 50)
    cout << "\n[Test 2] Deleting the last element (index 3)..." << endl;
    int val2 = arr.Delete(3);
    if (val2 != -1) {
        cout << "Deleted Value: " << val2 << endl;
    }
    arr.Display();

    // Test 3: Invalid Index Attempt
    cout << "\n[Test 3] Attempting to delete from invalid index -5..." << endl;
    arr.Delete(-5);
    
    return 0;
}