/*
Program Name: Linked List - Max Element (Iterative & Recursive)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Finding the maximum node value by scanning through the linked list.
   - Initial comparison baseline is set to the smallest integer possible (INT_MIN).

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Iterative Max : Loop while `p != NULL`. If `p->data > max`, update `max = p->data`.
   - Recursive Max : Base case `p == NULL` returns `INT_MIN`. Compare `p->data` with recursive result of `p->next`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) (Single linear scan).
   - Space Complexity : O(1) iterative, O(n) call stack space for recursive.
====================================================================================================
*/

#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* next;
};

// Global Head Pointer
Node* head = NULL;

// Function to Create Linked List from Array
void create(int A[], int n) {
    if (n <= 0) return;

    head = new Node();
    head->data = A[0];
    head->next = NULL;

    Node* last = head;

    for (int i = 1; i < n; i++) {
        Node* t = new Node();
        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

// 1. Iterative Max
int maxIterative(Node* p) {
    int maxVal = INT_MIN; // Minimum possible integer value

    while (p != NULL) {
        if (p->data > maxVal) {
            maxVal = p->data;
        }
        p = p->next; // Move to next node
    }
    return maxVal;
}

// 2. Recursive Max
int maxRecursive(Node* p) {
    int x = 0;

    if (p == NULL) {
        return INT_MIN; // Base Case
    }

    x = maxRecursive(p->next); // Recursive call for rest of the list

    return (x > p->data) ? x : p->data;
}

int main() {
    cout << "--- Linked List: Max Element Operations ---" << endl;

    int A[] = {12, 45, 7, 89, 23, 56};
    int n = 6;

    // Create Linked List
    create(A, n);

    // Display Results
    cout << "\nMaximum Element (Iterative) : " << maxIterative(head) << endl;
    cout << "Maximum Element (Recursive) : " << maxRecursive(head) << endl;

    return 0;
}