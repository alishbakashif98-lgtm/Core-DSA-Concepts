/*
Program Name: Array ADT - Binary Search (Iterative and Recursive)

Easy Notes (Important Concepts):
1. Pre-requisite: The array MUST be sorted (ascending or descending order).
2. Core Logic: 
   - Find the middle index: mid = (low + high) / 2
   - If the target 'key' matches the element at mid, search is complete!
   - If the key is smaller than mid, discard the right half by setting: high = mid - 1
   - If the key is larger than mid, discard the left half by setting: low = mid + 1
3. Time Complexity:
   - Best Case: O(1) (If the element is found exactly at the middle on the first try).
   - Worst/Average Case: O(log n) (Extremely fast because the search area shrinks by half each time).
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

    // 1. Iterative Binary Search (Using a simple loop)
    int IterativeBinarySearch(int key) {
        int low = 0;
        int high = length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (key == A[mid]) {
                return mid; // Found it!
            } else if (key < A[mid]) {
                high = mid - 1; // Move to the left half
            } else {
                low = mid + 1;  // Move to the right half
            }
        }
        return -1; // Not found
    }

    // 2. Recursive Binary Search (Using function call stack)
    int RecursiveBinarySearch(int low, int high, int key) {
        if (low <= high) {
            int mid = (low + high) / 2;

            if (key == A[mid]) {
                return mid; // Found it!
            } else if (key < A[mid]) {
                return RecursiveBinarySearch(low, mid - 1, key); // Search left half
            } else {
                return RecursiveBinarySearch(mid + 1, high, key); // Search right half
            }
        }
        return -1; // Not found
    }

    // Helper to set sorted mock data
    void SetSortedData() {
        A[0] = 10; A[1] = 20; A[2] = 30; A[3] = 40; A[4] = 50;
        length = 5;
    }
    
    int GetLength() { return length; }
};

int main() {
    Array arr(10);
    arr.SetSortedData(); // Populating sorted array: [10, 20, 30, 40, 50]
    
    cout << "--- Array ADT: Binary Search Showcase ---" << endl;
    arr.Display();
    
    int key = 40;
    
    // Testing Iterative Method
    cout << "\n[Iterative] Searching for key " << key << "..." << endl;
    int index1 = arr.IterativeBinarySearch(key);
    cout << "Result: Found at index " << index1 << endl;

    // Testing Recursive Method
    cout << "\n[Recursive] Searching for key " << key << "..." << endl;
    int index2 = arr.RecursiveBinarySearch(0, arr.GetLength() - 1, key);
    cout << "Result: Found at index " << index2 << endl;

    return 0;
}