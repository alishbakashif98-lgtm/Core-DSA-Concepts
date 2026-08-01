/*
Program Name: Linked List - Count Nodes and Sum of Elements (Iterative & Recursive)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Count: Traverse through nodes while incrementing a counter variable until NULL is reached.
   - Sum: Traverse through nodes and accumulate each node's `data` value into a sum variable.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Iterative Count : Initialize `c = 0`; while `p != NULL`, do `c++` and move `p = p->next`.
   - Iterative Sum   : Initialize `s = 0`; while `p != NULL`, do `s += p->data` and move `p = p->next`.
   - Recursive Count : If `p == NULL` return 0; else return `count(p->next) + 1`.
   - Recursive Sum   : If `p == NULL` return 0; else return `sum(p->next) + p->data`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) for all operations (single linear pass).
   - Auxiliary Space : O(1) for iterative, O(n) call stack space for recursive.
====================================================================================================
*/

#include <iostream>
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

// 1. Iterative Count
int countIterative(Node* p) {
    int c = 0;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

// 2. Recursive Count
int countRecursive(Node* p) {
    if (p == NULL) return 0;
    return countRecursive(p->next) + 1;
}

// 3. Iterative Sum
int sumIterative(Node* p) {
    int s = 0;
    while (p != NULL) {
        s += p->data;
        p = p->next;
    }
    return s;
}

// 4. Recursive Sum
int sumRecursive(Node* p) {
    if (p == NULL) return 0;
    return sumRecursive(p->next) + p->data;
}

int main() {
    cout << "--- Linked List: Count & Sum Operations ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List
    create(A, n);

    // Count Output
    cout << "\n[Count Operations]:" << endl;
    cout << "Total Nodes (Iterative) : " << countIterative(head) << endl;
    cout << "Total Nodes (Recursive) : " << countRecursive(head) << endl;

    // Sum Output
    cout << "\n[Sum Operations]:" << endl;
    cout << "Sum of Elements (Iterative) : " << sumIterative(head) << endl;
    cout << "Sum of Elements (Recursive) : " << sumRecursive(head) << endl;

    return 0;
}