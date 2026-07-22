/*
Program Name: Array ADT - Sorted Array Operations & Rearranging Numbers

1. INSERT IN A SORTED ARRAY:
----------------------------------------------------------------------------------------------------
   - Objective: Insert a new element 'x' into an ALREADY SORTED array while maintaining the sorted order.
   - Core Logic:
     1. Start scanning from the LAST element (i = length - 1) moving backwards towards index 0.
     2. As long as A[i] is GREATER than 'x', shift A[i] one position to the right: A[i + 1] = A[i].
     3. Stop the loop when you find an element smaller than or equal to 'x' (or reach index -1).
     4. Place 'x' at index `i + 1`.
     5. Increment `length++`.
   - Time Complexity:
     * Best Case: O(1) -> If 'x' is larger than all elements (0 shifts needed).
     * Worst Case: O(n) -> If 'x' is smaller than all elements (shifts all 'n' items to index 0).

2. IS SORTED CHECK:
----------------------------------------------------------------------------------------------------
   - Objective: Check whether all elements in the array are sorted in ascending order.
   - Core Logic:
     1. Loop through the array from index 0 up to `length - 2`.
     2. Compare adjacent elements: `A[i]` and `A[i + 1]`.
     3. If `A[i] > A[i + 1]`, the array is NOT sorted -> return `false` immediately.
     4. If loop completes without finding any wrong order -> return `true`.
   - Time Complexity: O(n).

3. REARRANGE POSITIVE AND NEGATIVE NUMBERS (TWO-POINTER METHOD):
----------------------------------------------------------------------------------------------------
   - Objective: Move all negative numbers to the left side and all positive numbers to the right side.
   - Core Logic (Hoare's Partitioning Technique):
     1. Set two indices: `i = 0` (left side) and `j = length - 1` (right side).
     2. Move `i` forward as long as `A[i]` is negative (`A[i] < 0`).
     3. Move `j` backward as long as `A[j]` is positive or zero (`A[j] >= 0`).
     4. If `i < j` and both stop, swap `A[i]` and `A[j]`.
     5. Repeat until `i >= j`.
   - Time Complexity: O(n) (Single pass with two pointers).
   - Space Complexity: O(1) (In-place sorting without extra arrays).
====================================================================================================
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

    // 1. Insert an element in a Sorted Array
    void InsertSorted(int x) {
        if (length >= size) {
            cout << "Insert Error: Array capacity full!" << endl;
            return;
        }

        int i = length - 1;
        while (i >= 0 && A[i] > x) {
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = x;
        length++;
        cout << "Successfully inserted " << x << " in sorted order." << endl;
    }

    // 2. Check if the Array is Sorted
    bool IsSorted() {
        for (int i = 0; i < length - 1; i++) {
            if (A[i] > A[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // 3. Rearrange Positives and Negatives (Two-Pointer Method)
    void RearrangePosNeg() {
        int i = 0;
        int j = length - 1;

        while (i < j) {
            while (A[i] < 0) { i++; }
            while (A[j] >= 0) { j--; }

            if (i < j) {
                Swap(&A[i], &A[j]);
            }
        }
    }

    // Helper methods for mock data
    void SetSortedData() {
        A[0] = 10; A[1] = 20; A[2] = 35; A[3] = 45; A[4] = 60;
        length = 5;
    }

    void SetUnsortedData() {
        A[0] = 10; A[1] = 50; A[2] = 20; A[3] = 40; A[4] = 30;
        length = 5;
    }

    void SetMixedData() {
        A[0] = -6; A[1] = 3; A[2] = -8; A[3] = 10; A[4] = 5; A[5] = -2; A[6] = 7;
        length = 7;
    }
};

int main() {
    Array arr(10);

    cout << "--- Array ADT: Sorted Operations & Rearrangement ---" << endl;

    // Test 1: Insert in Sorted Array
    arr.SetSortedData();
    cout << "\n[Test 1] Original Sorted Array: "; arr.Display();
    arr.InsertSorted(30);
    arr.Display();

    // Test 2: IsSorted Check
    cout << "\n[Test 2] Checking IsSorted Status..." << endl;
    cout << "Checking current array: "; arr.Display();
    cout << "Is Sorted? " << (arr.IsSorted() ? "Yes (True)" : "No (False)") << endl;

    arr.SetUnsortedData();
    cout << "Checking unsorted array: "; arr.Display();
    cout << "Is Sorted? " << (arr.IsSorted() ? "Yes (True)" : "No (False)") << endl;

    // Test 3: Rearrange Positives and Negatives
    cout << "\n[Test 3] Rearranging Positives & Negatives..." << endl;
    arr.SetMixedData();
    cout << "Before Rearranging: "; arr.Display();
    arr.RearrangePosNeg();
    cout << "After Rearranging (Negatives on left, Positives on right): "; arr.Display();

    return 0;
}