/*
Program Name: Array ADT - Set Operations (Union, Intersection, Difference)


1. UNION OF TWO SORTED ARRAYS ($A \cup B$):
----------------------------------------------------------------------------------------------------
   - Objective: Combine elements from both arrays without duplicates.
   - Core Logic (Two-Pointer Method):
     * Compare A[i] and B[j]:
       - If A[i] < B[j]: Copy A[i] to C[k], then increment `i++` and `k++`.
       - If B[j] < A[i]: Copy B[j] to C[k], then increment `j++` and `k++`.
       - If A[i] == B[j]: Copy ONLY ONE instance to C[k], then increment BOTH `i++`, `j++`, and `k++`.
     * Copy any remaining elements from either array into C.
   - Time Complexity: $O(m + n)$.

2. INTERSECTION OF TWO SORTED ARRAYS ($A \cap B$):
----------------------------------------------------------------------------------------------------
   - Objective: Extract ONLY the elements present in BOTH arrays.
   - Core Logic:
     * Compare A[i] and B[j]:
       - If A[i] < B[j]: Move `i++`.
       - If B[j] < A[i]: Move `j++`.
       - If A[i] == B[j]: Element exists in both! Copy A[i] to C[k], then increment `i++`, `j++`, and `k++`.
     * Once either array finishes, terminate (remaining items in the other array have no match).
   - Time Complexity: $O(m + n)$.

3. DIFFERENCE OF TWO SORTED ARRAYS ($A - B$):
----------------------------------------------------------------------------------------------------
   - Objective: Extract elements present in Array A but NOT present in Array B.
   - Core Logic:
     * Compare A[i] and B[j]:
       - If A[i] < B[j]: A[i] is unique to Array A! Copy A[i] to C[k], then increment `i++` and `k++`.
       - If B[j] < A[i]: Move `j++` (B[j] cannot match A[i]).
       - If A[i] == B[j]: Skip the element! Increment BOTH `i++` and `j++`.
     * Copy any leftover elements ONLY from Array A.
   - Time Complexity: $O(m + n)$.
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

    // Helper to fill array data
    void SetData(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            A[i] = arr[i];
        }
        length = n;
    }

    // 1. Set Union (A U B)
    static Array* SetUnion(Array *arr1, Array *arr2) {
        int i = 0, j = 0, k = 0;
        Array *arr3 = new Array(arr1->length + arr2->length);

        while (i < arr1->length && j < arr2->length) {
            if (arr1->A[i] < arr2->A[j]) {
                arr3->A[k++] = arr1->A[i++];
            } else if (arr2->A[j] < arr1->A[i]) {
                arr3->A[k++] = arr2->A[j++];
            } else { // Elements are equal -> Copy once, advance both
                arr3->A[k++] = arr1->A[i++];
                j++;
            }
        }

        for (; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
        for (; j < arr2->length; j++) arr3->A[k++] = arr2->A[j];

        arr3->length = k;
        return arr3;
    }

    // 2. Set Intersection (A N B)
    static Array* SetIntersection(Array *arr1, Array *arr2) {
        int i = 0, j = 0, k = 0;
        Array *arr3 = new Array(arr1->length + arr2->length);

        while (i < arr1->length && j < arr2->length) {
            if (arr1->A[i] < arr2->A[j]) {
                i++;
            } else if (arr2->A[j] < arr1->A[i]) {
                j++;
            } else { // Match found
                arr3->A[k++] = arr1->A[i++];
                j++;
            }
        }

        arr3->length = k;
        return arr3;
    }

    // 3. Set Difference (A - B)
    static Array* SetDifference(Array *arr1, Array *arr2) {
        int i = 0, j = 0, k = 0;
        Array *arr3 = new Array(arr1->length + arr2->length);

        while (i < arr1->length && j < arr2->length) {
            if (arr1->A[i] < arr2->A[j]) {
                arr3->A[k++] = arr1->A[i++];
            } else if (arr2->A[j] < arr1->A[i]) {
                j++;
            } else { // Match found -> ignore element from A
                i++;
                j++;
            }
        }

        for (; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];

        arr3->length = k;
        return arr3;
    }
};

int main() {
    cout << "--- Array ADT: Set Operations (Sorted Arrays) ---" << endl;

    Array arr1(10);
    int data1[] = {2, 6, 10, 15, 25};
    arr1.SetData(data1, 5);

    Array arr2(10);
    int data2[] = {3, 6, 15, 20, 30};
    arr2.SetData(data2, 5);

    cout << "Array 1 (A): "; arr1.Display();
    cout << "Array 2 (B): "; arr2.Display();

    // 1. Union
    cout << "\n[1] Set Union (A U B):" << endl;
    Array *union_arr = Array::SetUnion(&arr1, &arr2);
    union_arr->Display();

    // 2. Intersection
    cout << "\n[2] Set Intersection (A N B):" << endl;
    Array *intersect_arr = Array::SetIntersection(&arr1, &arr2);
    intersect_arr->Display();

    // 3. Difference
    cout << "\n[3] Set Difference (A - B):" << endl;
    Array *diff_arr = Array::SetDifference(&arr1, &arr2);
    diff_arr->Display();

    // Cleanup dynamic memory
    delete union_arr;
    delete intersect_arr;
    delete diff_arr;

    return 0;
}