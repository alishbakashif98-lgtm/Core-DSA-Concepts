/*
Program Name: Array ADT - Get, Set, Max, Min, Sum, and Average Operations

Important Concepts:
1. Get(index): Returns the value at a specific index. 
   - Condition: Index must be valid (index >= 0 && index < length). Time Complexity: O(1).
2. Set(index, x): Overwrites/replaces the element at a specific index with a new value 'x'. 
   - Condition: Index must be valid. Time Complexity: O(1).
3. Max() / Min(): Traverses the array to find the largest or smallest element.
   - Logic: Assume the first element (A[0]) is the max/min, then loop through the rest to compare. 
   - Time Complexity: O(n).
4. Sum(): Adds up all elements in the array.
   - Can be written using a simple loop or recursively. Time Complexity: O(n).
5. Avg(): Divides the total sum by the number of elements (length).
   - Cast to (float) to avoid integer division truncation.
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

    // 1. Get Operation
    int Get(int index) {
        if (index >= 0 && index < length) {
            return A[index];
        }
        cout << "Error: Invalid Index!" << endl;
        return -1;
    }

    // 2. Set Operation
    void Set(int index, int x) {
        if (index >= 0 && index < length) {
            A[index] = x;
            cout << "Successfully set index " << index << " to value " << x << endl;
        } else {
            cout << "Error: Invalid Index!" << endl;
        }
    }

    // 3. Max Operation
    int Max() {
        if (length == 0) return -1;
        int max_val = A[0];
        for (int i = 1; i < length; i++) {
            if (A[i] > max_val) {
                max_val = A[i];
            }
        }
        return max_val;
    }

    // 4. Min Operation
    int Min() {
        if (length == 0) return -1;
        int min_val = A[0];
        for (int i = 1; i < length; i++) {
            if (A[i] < min_val) {
                min_val = A[i];
            }
        }
        return min_val;
    }

    // 5. Sum Operation
    int Sum() {
        int total = 0;
        for (int i = 0; i < length; i++) {
            total += A[i];
        }
        return total;
    }

    // 6. Average Operation
    float Avg() {
        if (length == 0) return 0.0;
        return (float)Sum() / length;
    }

    // Helper to set mock data
    void SetMockData() {
        A[0] = 12; A[1] = 45; A[2] = 23; A[3] = 89; A[4] = 34;
        length = 5;
    }
};

int main() {
    Array arr(10);
    arr.SetMockData(); // Initial Array: [12, 45, 23, 89, 34]
    
    cout << "--- Array ADT: Get, Set, & Statistics Operations ---" << endl;
    arr.Display();
    
    // Testing Get & Set
    cout << "\n[Get] Element at index 3 is: " << arr.Get(3) << endl;
    arr.Set(2, 99); // Changing value at index 2 to 99
    arr.Display();
    
    // Testing Statistics Functions
    cout << "\n--- Array Analytics ---" << endl;
    cout << "Maximum Element: " << arr.Max() << endl;
    cout << "Minimum Element: " << arr.Min() << endl;
    cout << "Sum of Elements: " << arr.Sum() << endl;
    cout << "Average Value:   " << arr.Avg() << endl;

    return 0;
}