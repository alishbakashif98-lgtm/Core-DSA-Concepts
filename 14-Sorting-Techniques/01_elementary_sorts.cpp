/*
Program Name: Elementary Sorting Algorithms - Bubble Sort, Insertion Sort, Selection Sort


1. CONCEPTUAL DEFINITIONS:
----------------------------------------------------------------------------------------------------
   - Bubble Sort   : Repeatedly swaps adjacent out-of-order elements; bubbles largest to the end.
   - Insertion Sort: Inserts elements into their correct sorted position within an expanding sublist.
   - Selection Sort: Repeatedly selects the minimum element from the unsorted part and swaps it.

2. PROPERTIES & STABILITY:
----------------------------------------------------------------------------------------------------
   - Bubble Sort   : Stable, In-place, Adaptive (with flag: O(n) best case).
   - Insertion Sort: Stable, In-place, Adaptive (O(n) best case, ideal for linked lists/nearly sorted).
   - Selection Sort: Unstable, In-place, Non-adaptive (minimum swaps: O(n) swaps).

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  :
     * Bubble Sort   : Best O(n), Worst/Avg O(n^2)
     * Insertion Sort: Best O(n), Worst/Avg O(n^2)
     * Selection Sort: Best/Worst/Avg O(n^2)
   - Space Complexity : O(1) auxiliary space.
====================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class ElementarySorts {
public:
    // 1. Bubble Sort (Adaptive with flag)
    static void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            // If no elements were swapped in this pass, array is sorted
            if (!swapped) break;
        }
    }

    // 2. Insertion Sort
    static void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            // Shift elements greater than key to one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // 3. Selection Sort
    static void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap found minimum with current index
            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
            }
        }
    }

    // Utility: Print Array
    static void display(const vector<int>& arr) {
        for (int x : arr) cout << x << " ";
        cout << endl;
    }
};

int main() {
    cout << "--- Elementary Comparison-Based Sorting Algorithms ---" << endl;

    vector<int> sample = {64, 25, 12, 22, 11};

    // 1. Bubble Sort Demo
    vector<int> arr1 = sample;
    cout << "\nOriginal Array : "; ElementarySorts::display(arr1);
    ElementarySorts::bubbleSort(arr1);
    cout << "Bubble Sorted  : "; ElementarySorts::display(arr1);

    // 2. Insertion Sort Demo
    vector<int> arr2 = sample;
    cout << "\nOriginal Array : "; ElementarySorts::display(arr2);
    ElementarySorts::insertionSort(arr2);
    cout << "Insertion Sorted: "; ElementarySorts::display(arr2);

    // 3. Selection Sort Demo
    vector<int> arr3 = sample;
    cout << "\nOriginal Array : "; ElementarySorts::display(arr3);
    ElementarySorts::selectionSort(arr3);
    cout << "Selection Sorted: "; ElementarySorts::display(arr3);

    return 0;
}