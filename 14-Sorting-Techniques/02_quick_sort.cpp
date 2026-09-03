/*
Program Name: Quick Sort Algorithm (Divide and Conquer Partitioning)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Quick Sort is an efficient, in-place, divide-and-conquer sorting algorithm.
   - Selects a pivot element and partitions the array such that:
     * All elements smaller than or equal to pivot are placed to its left.
     * All elements greater than pivot are placed to its right.
     * Recursively repeats on left and right partitions.

2. PROPERTIES & CHARACTERISTICS:
----------------------------------------------------------------------------------------------------
   - Stability       : Unstable (relative order of equal elements can change during partition swaps).
   - In-Place        : Yes (auxiliary space is O(log n) call stack only).
   - Worst-Case Input: Already sorted or reverse sorted array (when first/last element is picked as pivot).

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  :
     * Best Case   : O(n log n) [Pivot divides array into equal halves]
     * Average Case: O(n log n)
     * Worst Case  : O(n^2)     [Array already sorted / unbalanced partitions]
   - Space Complexity : O(log n) recursion call stack memory (O(n) in worst case).
====================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class QuickSorter {
private:
    // Partitioning method (Abdul Bari's approach using first element as pivot)
    static int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j) {
            // Move i right until finding an element greater than pivot
            while (i <= high && arr[i] <= pivot) {
                i++;
            }

            // Move j left until finding an element smaller than or equal to pivot
            while (j >= low && arr[j] > pivot) {
                j--;
            }

            // Swap out-of-order elements
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        // Place pivot in its correct sorted position
        swap(arr[low], arr[j]);
        return j;
    }

    // Recursive Quick Sort engine
    static void quickSortRecursive(vector<int>& arr, int low, int high) {
        if (low < high) {
            int partitionIndex = partition(arr, low, high);

            // Sort left partition
            quickSortRecursive(arr, low, partitionIndex - 1);

            // Sort right partition
            quickSortRecursive(arr, partitionIndex + 1, high);
        }
    }

public:
    // Public sorting interface
    static void sort(vector<int>& arr) {
        if (arr.empty()) return;
        quickSortRecursive(arr, 0, arr.size() - 1);
    }

    // Display helper
    static void display(const vector<int>& arr) {
        for (int x : arr) cout << x << " ";
        cout << endl;
    }
};

int main() {
    cout << "--- Quick Sort (Divide and Conquer Partitioning) ---" << endl;

    vector<int> data = {50, 70, 60, 90, 40, 80, 10, 20, 30};

    cout << "Original Unsorted Array : ";
    QuickSorter::display(data);

    QuickSorter::sort(data);

    cout << "Sorted Array (QuickSort): ";
    QuickSorter::display(data);

    return 0;
}