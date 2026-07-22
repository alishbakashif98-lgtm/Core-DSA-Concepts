/*
Program Name: Array ADT - Reverse and Shift Operations

Important Concepts:
1. Reverse (Auxiliary Array Method):
   - Uses a secondary temporary array in heap.
   - Copies elements from original array end-to-beginning into temp array, then copies back.
   - Time Complexity: O(n), Space Complexity: O(n) (requires extra memory).

2. Reverse (Two-Pointer In-Place Method) [RECOMMENDED]:
   - Uses two pointers/indices: 'i' starting at 0 and 'j' starting at length-1.
   - Swaps A[i] and A[j], then increments 'i' and decrements 'j' until they meet in the middle.
   - Time Complexity: O(n), Space Complexity: O(1) (no extra memory needed).

3. Left Shift / Right Shift:
   - Shifts all elements left or right by one or more positions.
   - Vacated positions are filled with 0.
*/

#include <iostream>
using namespace std;

class Array {
private:
    int *A;      // Pointer to dynamic array in Heap
    int size;    // Total capacity
    int length;  // Current number of elements

    // Helper Swap Function
    void Swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

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

    // 1. Reverse using Auxiliary Array - Space Complexity: O(n)
    void ReverseAuxiliary() {
        int *B = new int[length]; // Temporary array
        
        // Copy elements backwards
        for (int i = length - 1, j = 0; i >= 0; i--, j++) {
            B[j] = A[i];
        }
        
        // Copy back to original array
        for (int i = 0; i < length; i++) {
            A[i] = B[i];
        }
        
        delete []B; // Free auxiliary memory
    }

    // 2. Reverse In-Place (Two-Pointer Method) - Space Complexity: O(1)
    void ReverseInPlace() {
        for (int i = 0, j = length - 1; i < j; i++, j--) {
            Swap(&A[i], &A[j]);
        }
    }

    // 3. Left Shift by 1 position
    void LeftShift() {
        if (length <= 1) return;
        for (int i = 0; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        A[length - 1] = 0; // Fill last index with 0
    }

    // Helper to set mock data
    void SetMockData() {
        A[0] = 10; A[1] = 20; A[2] = 30; A[3] = 40; A[4] = 50;
        length = 5;
    }
};

int main() {
    Array arr(10);
    
    cout << "--- Array ADT: Reverse & Shift Operations ---" << endl;
    
    // Test 1: In-Place Reverse
    arr.SetMockData();
    cout << "\nOriginal Array: "; arr.Display();
    arr.ReverseInPlace();
    cout << "After In-Place Reversing: "; arr.Display();

    // Test 2: Auxiliary Array Reverse
    arr.SetMockData();
    arr.ReverseAuxiliary();
    cout << "After Auxiliary Reversing: "; arr.Display();

    // Test 3: Left Shift
    arr.SetMockData();
    cout << "\nBefore Left Shift: "; arr.Display();
    arr.LeftShift();
    cout << "After Left Shift (first element removed, 0 added at end): "; arr.Display();

    return 0;
}