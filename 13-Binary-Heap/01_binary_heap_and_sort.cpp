/*
Program Name: Binary Max Heap - Insertion, Deletion, Heapify, and Heap Sort


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Binary Heap is a complete binary tree implemented via contiguous array storage.
   - Max Heap Invariant: Key of every parent node is >= keys of its children.
   - Enables efficient Priority Queue implementations and in-place Heap Sort.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Insert(val)   : Place at end of heap, bubble up by comparing with parent ((i-1)/2).
   - Delete()      : Swap root with last element, reduce heap size, sift down to correct position.
   - Heapify(arr)  : Build heap in O(n) bottom-up starting from index (n/2 - 1) down to 0.
   - HeapSort(arr) : Heapify array, then repeatedly delete root to place maximum at the end.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  :
     * Insert / Delete : O(log n)
     * Heapify (Build) : O(n)
     * Heap Sort       : O(n log n)
   - Space Complexity : O(1) in-place auxiliary space.
====================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// Max Heap Class
class MaxHeap {
private:
    vector<int> heap;

    // Sift-down helper for Heapify and Deletion
    void siftDown(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            siftDown(arr, n, largest);
        }
    }

public:
    MaxHeap() {}

    // Insert element into Max Heap (Bottom-Up)
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Bubble up
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] > heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    // Delete Root (Maximum element)
    int deleteRoot() {
        if (heap.empty()) {
            cout << "Heap Underflow!" << endl;
            return -1;
        }

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            siftDown(heap, heap.size(), 0);
        }

        return maxVal;
    }

    // O(n) Bottom-Up Heapify Method
    static void heapify(vector<int>& arr) {
        int n = arr.size();
        for (int i = (n / 2) - 1; i >= 0; i--) {
            MaxHeap temp;
            temp.siftDown(arr, n, i);
        }
    }

    // Heap Sort (In-Place Ascending)
    static void heapSort(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Build Max Heap
        heapify(arr);

        // Step 2: Extract elements one by one from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current maximum (root) to the end
            swap(arr[0], arr[i]);

            // Restore heap property on remaining elements
            MaxHeap temp;
            temp.siftDown(arr, i, 0);
        }
    }

    // Display current Heap
    void displayHeap() {
        cout << "Max Heap Array: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Binary Max Heap Operations ---" << endl;

    MaxHeap heap;

    // 1. Dynamic Insertions
    int elements[] = {10, 20, 15, 30, 40};
    cout << "Inserting elements: ";
    for (int val : elements) {
        cout << val << " ";
        heap.insert(val);
    }
    cout << "\n\n";

    heap.displayHeap();

    // 2. Delete Root
    cout << "Deleted Root (Max Element): " << heap.deleteRoot() << endl;
    heap.displayHeap();

    cout << "\n--- Heapify and Heap Sort ---" << endl;

    // 3. O(n) Heapify & Heap Sort Demo
    vector<int> unsortedArr = {45, 12, 85, 32, 89, 39, 69, 44, 42, 1, 90};

    cout << "Original Unsorted Array : ";
    for (int x : unsortedArr) cout << x << " ";
    cout << endl;

    MaxHeap::heapify(unsortedArr);
    cout << "Array after Heapify (Max Heap): ";
    for (int x : unsortedArr) cout << x << " ";
    cout << endl;

    MaxHeap::heapSort(unsortedArr);
    cout << "Sorted Array (Heap Sort)      : ";
    for (int x : unsortedArr) cout << x << " ";
    cout << endl;

    return 0;
}