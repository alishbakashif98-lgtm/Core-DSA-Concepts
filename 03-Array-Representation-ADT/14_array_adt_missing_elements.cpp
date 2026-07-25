/*
Program Name: Array ADT - Finding Missing Elements


1. SINGLE MISSING ELEMENT IN FIRST 'N' NATURAL NUMBERS:
----------------------------------------------------------------------------------------------------
   - Formula Method: Sum of first 'n' natural numbers = n * (n + 1) / 2
   - Logic: Calculate expected sum using formula, then subtract actual sum of array elements.
   - Time Complexity: O(n), Space Complexity: O(1).

2. SINGLE MISSING ELEMENT IN A SORTED ARRAY (NOT STARTING FROM 1):
----------------------------------------------------------------------------------------------------
   - Index Difference Method: In a consecutive sequence, (A[i] - i) should remain constant (diff).
   - Logic: Calculate `diff = A[0] - 0`. Loop through array; if `A[i] - i != diff`, the missing 
     element is `i + diff`.
   - Time Complexity: O(n), Space Complexity: O(1).

3. MULTIPLE MISSING ELEMENTS IN A SORTED ARRAY:
----------------------------------------------------------------------------------------------------
   - Extended Index Difference Method: When `A[i] - i != diff`, print `i + diff` repeatedly 
     and increment `diff++` until `diff == A[i] - i`.
   - Time Complexity: O(n), Space Complexity: O(1).

4. MULTIPLE MISSING ELEMENTS IN AN UNSORTED ARRAY (HASH TABLE / BITSET):
----------------------------------------------------------------------------------------------------
   - Hashing Method: Create a Bitset / Hash array initialized to 0.
   - Logic: Mark `Hash[A[i]] = 1` for all elements. Then iterate through Hash array; 
     indices with 0 value represent missing numbers.
   - Time Complexity: O(n), Space Complexity: O(max_element).
====================================================================================================
*/

#include <iostream>
using namespace std;

class MissingElements {
public:
    // 1. Single Missing Element in First N Natural Numbers
    static int SingleMissingFirstN(int A[], int n, int lastElement) {
        int expectedSum = lastElement * (lastElement + 1) / 2;
        int actualSum = 0;
        for (int i = 0; i < n; i++) {
            actualSum += A[i];
        }
        return expectedSum - actualSum;
    }

    // 2. Single Missing Element in Sorted Array (Difference Method)
    static int SingleMissingSorted(int A[], int n) {
        int diff = A[0] - 0;
        for (int i = 0; i < n; i++) {
            if (A[i] - i != diff) {
                return i + diff;
            }
        }
        return -1;
    }

    // 3. Multiple Missing Elements in Sorted Array
    static void MultipleMissingSorted(int A[], int n) {
        int diff = A[0] - 0;
        cout << "Missing elements: ";
        for (int i = 0; i < n; i++) {
            if (A[i] - i != diff) {
                while (diff < A[i] - i) {
                    cout << (i + diff) << " ";
                    diff++;
                }
            }
        }
        cout << endl;
    }

    // 4. Multiple Missing Elements in Unsorted Array (Hashing Method)
    static void MultipleMissingUnsorted(int A[], int n, int maxVal) {
        int *H = new int[maxVal + 1](); // Dynamic array initialized to 0
        
        for (int i = 0; i < n; i++) {
            H[A[i]]++;
        }

        cout << "Missing elements: ";
        for (int i = 1; i <= maxVal; i++) {
            if (H[i] == 0) {
                cout << i << " ";
            }
        }
        cout << endl;

        delete []H;
    }
};

int main() {
    cout << "--- Array ADT: Finding Missing Elements Showcase ---" << endl;

    // Case 1: First N Natural Numbers
    int A1[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    cout << "\n[Case 1] First N Natural Numbers Missing Item: " 
         << MissingElements::SingleMissingFirstN(A1, 9, 10) << endl;

    // Case 2: Sorted Array Single Missing
    int A2[] = {6, 7, 8, 9, 10, 12, 13, 14};
    cout << "\n[Case 2] Sorted Array Single Missing Item: " 
         << MissingElements::SingleMissingSorted(A2, 8) << endl;

    // Case 3: Sorted Array Multiple Missing
    int A3[] = {6, 7, 9, 11, 12, 15, 16};
    cout << "\n[Case 3] Sorted Array Multiple Items: ";
    MissingElements::MultipleMissingSorted(A3, 7);

    // Case 4: Unsorted Array Multiple Missing (Hashing)
    int A4[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    cout << "\n[Case 4] Unsorted Array Multiple Items (Hashing): ";
    MissingElements::MultipleMissingUnsorted(A4, 10, 12);

    return 0;
}