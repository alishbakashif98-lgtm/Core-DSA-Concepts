/*
Program Name: Array ADT - Finding Duplicates and Target Sum Pairs


1. DUPLICATES IN SORTED ARRAYS:
----------------------------------------------------------------------------------------------------
   - Adjacent Comparison Method: Iterate through the array; if `A[i] == A[i + 1]`, a duplicate exists.
     To count total occurrences, use a nested loop or secondary pointer `j = i + 1`.
   - Time Complexity: O(n), Space Complexity: O(1).

2. DUPLICATES IN UNSORTED ARRAYS (HASH TABLE):
----------------------------------------------------------------------------------------------------
   - Hash Array Frequency Counting: Increment `Hash[A[i]]++` for every element.
   - Any index in the Hash array with value > 1 is a duplicate element.
   - Time Complexity: O(n), Space Complexity: O(max_element).

3. PAIR WITH SUM K IN UNSORTED ARRAY (HASH TABLE):
----------------------------------------------------------------------------------------------------
   - Logic: For each element `A[i]`, check if `Hash[K - A[i]] > 0`.
   - If found, a valid pair `(A[i], K - A[i])` exists. Then mark `Hash[A[i]]++`.
   - Time Complexity: O(n), Space Complexity: O(max_element).

4. PAIR WITH SUM K IN SORTED ARRAY (TWO-POINTER TECHNIQUE):
----------------------------------------------------------------------------------------------------
   - Logic: Set `i = 0` and `j = n - 1`.
     * If `A[i] + A[j] == K`, pair found! Increment `i++` and decrement `j--`.
     * If `A[i] + A[j] < K`, increment `i++` (need a larger sum).
     * If `A[i] + A[j] > K`, decrement `j--` (need a smaller sum).
   - Time Complexity: O(n), Space Complexity: O(1).
====================================================================================================
*/

#include <iostream>
using namespace std;

class ArrayAnalysis {
public:
    // 1. Find and Count Duplicates in Sorted Array
    static void DuplicatesInSorted(int A[], int n) {
        cout << "Duplicates in Sorted Array: " << endl;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] == A[i + 1]) {
                int j = i + 1;
                while (j < n && A[j] == A[i]) { j++; }
                cout << "  Element " << A[i] << " appears " << (j - i) << " times." << endl;
                i = j - 1;
            }
        }
    }

    // 2. Find Duplicates in Unsorted Array using Hash Table
    static void DuplicatesInUnsortedHash(int A[], int n, int maxVal) {
        int *H = new int[maxVal + 1]();
        for (int i = 0; i < n; i++) {
            H[A[i]]++;
        }

        cout << "Duplicates in Unsorted Array (Hashing): " << endl;
        for (int i = 0; i <= maxVal; i++) {
            if (H[i] > 1) {
                cout << "  Element " << i << " appears " << H[i] << " times." << endl;
            }
        }
        delete []H;
    }

    // 3. Find Pairs with Sum K in Unsorted Array using Hash Table
    static void TargetSumPairHash(int A[], int n, int K, int maxVal) {
        int *H = new int[maxVal + 1]();
        cout << "Pairs with Sum " << K << " (Unsorted Hashing): " << endl;

        for (int i = 0; i < n; i++) {
            int complement = K - A[i];
            if (complement >= 0 && complement <= maxVal && H[complement] > 0) {
                cout << "  Pair Found: (" << A[i] << ", " << complement << ")" << endl;
            }
            H[A[i]]++;
        }
        delete []H;
    }

    // 4. Find Pairs with Sum K in Sorted Array (Two-Pointer Method)
    static void TargetSumPairSorted(int A[], int n, int K) {
        int i = 0;
        int j = n - 1;
        cout << "Pairs with Sum " << K << " (Sorted Two-Pointer): " << endl;

        while (i < j) {
            int currentSum = A[i] + A[j];
            if (currentSum == K) {
                cout << "  Pair Found: (" << A[i] << ", " << A[j] << ")" << endl;
                i++;
                j--;
            } else if (currentSum < K) {
                i++;
            } else {
                j--;
            }
        }
    }
};

int main() {
    cout << "--- Array ADT: Duplicates & Target Sum Pairs Showcase ---" << endl;

    // 1. Duplicates in Sorted Array
    int A1[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    cout << "\n[Test 1] Sorted Array Duplicates:" << endl;
    ArrayAnalysis::DuplicatesInSorted(A1, 10);

    // 2. Duplicates in Unsorted Array
    int A2[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    cout << "\n[Test 2] Unsorted Array Duplicates (Hashing):" << endl;
    ArrayAnalysis::DuplicatesInUnsortedHash(A2, 10, 8);

    // 3. Target Sum Pairs in Unsorted Array
    int A3[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    cout << "\n[Test 3] Target Sum Pairs K = 10 (Unsorted Array):" << endl;
    ArrayAnalysis::TargetSumPairHash(A3, 10, 10, 16);

    // 4. Target Sum Pairs in Sorted Array
    int A4[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    cout << "\n[Test 4] Target Sum Pairs K = 10 (Sorted Array):" << endl;
    ArrayAnalysis::TargetSumPairSorted(A4, 10, 10);

    return 0;
}