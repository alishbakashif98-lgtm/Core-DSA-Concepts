/*
Program Name: Array ADT - Linear Search with Optimizations

Easy Notes (Important Concepts):
1. Linear Search: Checking every element in the array one by one starting from 
   index 0 until the target 'key' is found or the array ends.
   - Time Complexity: O(n) (Because if the element is at the end, we scan everything).

2. Transposition (Optimization Method A):
   - When the target element is found, swap it with its previous element (index - 1).
   - Benefit: If the same element is searched frequently, it slowly crawls to the front, 
     reducing the number of steps for future searches.

3. Move-To-Head (Optimization Method B):
   - When the target element is found, swap it directly with the element at index 0.
   - Benefit: The next time that same element is searched, it is found instantly in O(1) time.
*/

#include <iostream>
using namespace std;

class Array {
private:
    int *A;      // Pointer to dynamic array in Heap
    int size;    // Total capacity
    int length;  // Current number of elements

    // A simple helper function to swap two values
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

    // 1. Standard Linear Search
    int LinearSearch(int key) {
        for (int i = 0; i < length; i++) {
            if (A[i] == key) {
                return i; // Found the key, returning its index
            }
        }
        return -1; // Key not found
    }

    // 2. Optimized Search using Transposition
    int LinearSearchTransposition(int key) {
        for (int i = 0; i < length; i++) {
            if (A[i] == key) {
                if (i > 0) { // Index 0 cannot be moved further back
                    Swap(&A[i], &A[i - 1]);
                    return i - 1; // Returning the new index position
                }
                return i;
            }
        }
        return -1;
    }

    // 3. Optimized Search using Move-To-Head
    int LinearSearchMoveToHead(int key) {
        for (int i = 0; i < length; i++) {
            if (A[i] == key) {
                Swap(&A[i], &A[0]); // Jumping the element directly to index 0
                return 0; // The element is now at the head position
            }
        }
        return -1;
    }

    // Helper method to fill array with mock data for testing
    void SetMockData() {
        A[0] = 40; A[1] = 10; A[2] = 20; A[3] = 50; A[4] = 30;
        length = 5;
    }
};

int main() {
    Array arr(10);
    
    cout << "--- Array ADT: Linear Search Showcase ---" << endl;
    
    // 1. Test Standard Search
    arr.SetMockData();
    arr.Display();
    int key = 20;
    cout << "Searching for 20... Found at index: " << arr.LinearSearch(key) << "\n" << endl;

    // 2. Test Transposition
    arr.SetMockData();
    cout << "Before Transposition Search: "; arr.Display();
    arr.LinearSearchTransposition(50);
    cout << "After Transposition (50 moved 1 step ahead): "; arr.Display();
    cout << endl;

    // 3. Test Move-To-Head
    arr.SetMockData();
    cout << "Before Move-To-Head Search: "; arr.Display();
    arr.LinearSearchMoveToHead(30);
    cout << "After Move-To-Head (30 jumped to index 0): "; arr.Display();

    return 0;
}