/*
Program Name: Non-Comparison Linear Sorts - Count Sort, Bucket/Bin Sort, and Radix Sort


1. CONCEPTUAL DEFINITIONS:
----------------------------------------------------------------------------------------------------
   - Count Sort      : Uses elements as direct indices in a frequency count array to reconstruct order.
   - Bucket/Bin Sort : Uses an array of Linked List bins indexed by element values.
   - Radix Sort      : Passes elements through 10 fixed bins (0-9) digit-by-digit from LSD to MSD.

2. PROPERTIES & TRADEOFFS:
----------------------------------------------------------------------------------------------------
   - Non-Comparison  : Beats the O(n log n) theoretical lower bound of comparison-based sorting.
   - Space Overhead  : Requires auxiliary memory proportional to the maximum value range or digit count.
   - Stability       : Preserves original relative order when bins act as FIFO queues.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  :
     * Count Sort  : O(n + max_val)
     * Bucket Sort : O(n + max_val)
     * Radix Sort  : O(d * n) where d is the number of digits in max_val
   - Space Complexity : O(max_val) for Count/Bucket, O(n) for Radix Sort.
====================================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node for Linked-List Bins
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class NonComparisonSorts {
private:
    // Helper: Find Maximum Element
    static int getMax(const vector<int>& arr) {
        int mx = arr[0];
        for (int x : arr) {
            if (x > mx) mx = x;
        }
        return mx;
    }

    // Helper: Append to end of linked list bin (FIFO for stability)
    static void insertBin(Node*& head, Node*& tail, int val) {
        Node* t = new Node(val);
        if (head == NULL) {
            head = tail = t;
        } else {
            tail->next = t;
            tail = t;
        }
    }

    // Helper: Delete node from front of linked list bin
    static int deleteBin(Node*& head, Node*& tail) {
        if (head == NULL) return -1;
        Node* p = head;
        int val = p->data;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete p;
        return val;
    }

public:
    // 1. Count Sort
    static void countSort(vector<int>& arr) {
        if (arr.empty()) return;
        int maxVal = getMax(arr);

        vector<int> count(maxVal + 1, 0);

        for (int x : arr) {
            count[x]++;
        }

        int i = 0, j = 0;
        while (i <= maxVal) {
            if (count[i] > 0) {
                arr[j++] = i;
                count[i]--;
            } else {
                i++;
            }
        }
    }

    // 2. Bucket / Bin Sort (Linked-List Array Approach)
    static void bucketSort(vector<int>& arr) {
        if (arr.empty()) return;
        int maxVal = getMax(arr);

        vector<Node*> heads(maxVal + 1, NULL);
        vector<Node*> tails(maxVal + 1, NULL);

        for (int x : arr) {
            insertBin(heads[x], tails[x], x);
        }

        int j = 0;
        for (int i = 0; i <= maxVal; i++) {
            while (heads[i] != NULL) {
                arr[j++] = deleteBin(heads[i], tails[i]);
            }
        }
    }

    // 3. Radix Sort (Base-10 LSD with Queued Linked Bins)
    static void radixSort(vector<int>& arr) {
        if (arr.empty()) return;
        int maxVal = getMax(arr);

        // Process for every digit place: 1, 10, 100, ...
        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            vector<Node*> heads(10, NULL);
            vector<Node*> tails(10, NULL);

            // Distribute into 10 decimal bins based on current digit
            for (int x : arr) {
                int binIndex = (x / exp) % 10;
                insertBin(heads[binIndex], tails[binIndex], x);
            }

            // Collect back into array in order
            int j = 0;
            for (int i = 0; i < 10; i++) {
                while (heads[i] != NULL) {
                    arr[j++] = deleteBin(heads[i], tails[i]);
                }
            }
        }
    }

    // Utility: Print Vector
    static void display(const vector<int>& arr) {
        for (int x : arr) cout << x << " ";
        cout << endl;
    }
};

int main() {
    cout << "--- Non-Comparison Linear Time Sorting Algorithms ---" << endl;

    vector<int> sample1 = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    cout << "\nOriginal Array 1       : "; NonComparisonSorts::display(sample1);
    NonComparisonSorts::countSort(sample1);
    cout << "Sorted with Count Sort : "; NonComparisonSorts::display(sample1);

    vector<int> sample2 = {8, 3, 7, 4, 9, 2, 6, 5, 8, 3};
    cout << "\nOriginal Array 2       : "; NonComparisonSorts::display(sample2);
    NonComparisonSorts::bucketSort(sample2);
    cout << "Sorted with Bucket Sort: "; NonComparisonSorts::display(sample2);

    vector<int> sample3 = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    cout << "\nOriginal Array 3       : "; NonComparisonSorts::display(sample3);
    NonComparisonSorts::radixSort(sample3);
    cout << "Sorted with Radix Sort : "; NonComparisonSorts::display(sample3);

    return 0;
}