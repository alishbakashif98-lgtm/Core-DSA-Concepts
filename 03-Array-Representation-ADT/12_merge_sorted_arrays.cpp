/*
Program Name: Array ADT - Merging Two Sorted Arrays


1. MERGING TWO SORTED ARRAYS:
----------------------------------------------------------------------------------------------------
   - Pre-requisite: Both input arrays MUST be sorted beforehand.
   - Objective: Combine elements of Array 1 (length = m) and Array 2 (length = n) into a new 
     Array 3 (capacity = m + n) in sorted order.

   - Core Algorithm Logic (Three-Pointer Method):
     1. Initialize three index pointers:
        * `i = 0` (for Array 1)
        * `j = 0` (for Array 2)
        * `k = 0` (for Array 3)
     2. Loop while BOTH pointers are valid (`i < length1` AND `j < length2`):
        * Compare `A[i]` and `B[j]`.
        * Whichever element is SMALLER gets copied to `C[k]`.
        * Increment `k++` and increment the pointer of the array from which the item was taken.
     3. Copy Leftover Elements:
        * When the loop ends, one array will still have remaining elements.
        * Use two separate loops to copy any leftover items directly into `C`.

   - Time Complexity:
     * O(m + n) -> Linear time relative to the sum of lengths of both arrays.
     * Each element is compared and copied exactly once.

   - Space Complexity:
     * O(m + n) -> Requires extra heap memory for the merged third array.
====================================================================================================
*/

#include <iostream>
using namespace std;

class Array {
private:
    int *A;      // Pointer to dynamic array in Heap
    int size;    // Total capacity
    int length;  // Current number of elements

public:
    // Parameterized Constructor
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

    // Getter methods
    int GetLength() { return length; }
    int GetSize() { return size; }
    int* GetArrayPointer() { return A; }

    // Helper method to populate array data
    void SetData(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            A[i] = arr[i];
        }
        length = n;
    }

    // --- MERGE OPERATION ---
    // Returns a pointer to a newly allocated merged Array object
    static Array* Merge(Array *arr1, Array *arr2) {
        int i = 0, j = 0, k = 0;

        // Allocate dynamic memory for the resulting merged Array
        int total_length = arr1->length + arr2->length;
        Array *arr3 = new Array(total_length);

        int *A1 = arr1->A;
        int *A2 = arr2->A;
        int *A3 = arr3->A;

        // Step 1: Compare and copy the smaller element
        while (i < arr1->length && j < arr2->length) {
            if (A1[i] < A2[j]) {
                A3[k++] = A1[i++];
            } else {
                A3[k++] = A2[j++];
            }
        }

        // Step 2: Copy remaining elements from Array 1 (if any)
        for (; i < arr1->length; i++) {
            A3[k++] = A1[i];
        }

        // Step 3: Copy remaining elements from Array 2 (if any)
        for (; j < arr2->length; j++) {
            A3[k++] = A2[j];
        }

        arr3->length = total_length;
        return arr3;
    }
};

int main() {
    cout << "--- Array ADT: Merging Two Sorted Arrays ---" << endl;

    // Creating two sorted source arrays
    Array arr1(10);
    int data1[] = {3, 8, 16, 20, 25};
    arr1.SetData(data1, 5);

    Array arr2(10);
    int data2[] = {4, 10, 12, 22, 23};
    arr2.SetData(data2, 5);

    cout << "Array 1: "; arr1.Display();
    cout << "Array 2: "; arr2.Display();

    // Merging Array 1 and Array 2
    cout << "\nMerging both sorted arrays into Array 3..." << endl;
    Array *arr3 = Array::Merge(&arr1, &arr2);

    cout << "Merged Array 3: "; arr3->Display();

    // Clean up dynamic merged array memory
    delete arr3;

    return 0;
}