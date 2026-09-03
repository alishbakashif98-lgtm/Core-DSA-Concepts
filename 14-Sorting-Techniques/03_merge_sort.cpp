/*
Program Name: Merge Sort - Recursive and Iterative (2-Way Merging)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Merge Sort is a divide-and-conquer algorithm that divides an input array into two halves,
     sorts them independently, and merges the two sorted halves into a single sorted sequence.
   - Operates both recursively (top-down) and iteratively (bottom-up 2-way merges).

2. PROPERTIES & CHARACTERISTICS:
----------------------------------------------------------------------------------------------------
   - Stability       : Stable (preserves original order of duplicates during <= merge comparisons).
   - In-Place        : No (requires O(n) auxiliary storage for the merge step).
   - Predictability  : Consistent O(n log n) runtime regardless of input order (best, avg, worst).

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n log n) across Best, Average, and Worst cases.
   - Space Complexity : O(n) auxiliary array buffer + O(log n) stack frames for recursive variant.
====================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class MergeSorter {
private:
    // Core 2-Way Merge Subroutine
    static void merge(vector<int>& arr, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = 0;
        vector<int> temp(high - low + 1);

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= high) {
            temp[k++] = arr[j++];
        }

        // Copy back to original array
        for (int idx = 0; idx < k; idx++) {
            arr[low + idx] = temp[idx];
        }
    }

    // Recursive helper (Top-Down)
    static void recursiveMergeSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            recursiveMergeSort(arr, low, mid);
            recursiveMergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

public:
    // 1. Recursive Interface (Top-Down)
    static void sortRecursive(vector<int>& arr) {
        if (arr.size() <= 1) return;
        recursiveMergeSort(arr, 0, arr.size() - 1);
    }

    // 2. Iterative Interface (Bottom-Up 2-Way Merge)
    static void sortIterative(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;

        int p; // Pass size (1, 2, 4, 8, ...)
        for (p = 2; p <= n; p = p * 2) {
            for (int i = 0; i + p - 1 < n; i = i + p) {
                int low = i;
                int high = i + p - 1;
                int mid = low + (high - low) / 2;
                merge(arr, low, mid, high);
            }
        }

        // Merge remaining odd partition if array length is not power of 2
        if (p / 2 < n) {
            merge(arr, 0, (p / 2) - 1, n - 1);
        }
    }

    // Display helper
    static void display(const vector<int>& arr) {
        for (int x : arr) cout << x << " ";
        cout << endl;
    }
};

int main() {
    cout << "--- Merge Sort (Recursive & Iterative 2-Way) ---" << endl;

    vector<int> data1 = {8, 3, 7, 4, 9, 2, 6, 5};
    cout << "Original Array 1          : ";
    MergeSorter::display(data1);

    MergeSorter::sortRecursive(data1);
    cout << "Sorted (Recursive Merge)  : ";
    MergeSorter::display(data1);

    cout << "\n------------------------------------------------\n";

    vector<int> data2 = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    cout << "Original Array 2          : ";
    MergeSorter::display(data2);

    MergeSorter::sortIterative(data2);
    cout << "Sorted (Iterative Merge)  : ";
    MergeSorter::display(data2);

    return 0;
}