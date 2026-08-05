/*
Program Name: Doubly Linked List - Creation and Display


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Doubly Linked List (DLL) is a linear data structure where each node contains three parts:
     1. `prev` pointer pointing to the previous node.
     2. `data` element holding the value.
     3. `next` pointer pointing to the next node.
   - It allows traversal in both forward and backward directions.

2. STEP-BY-STEP FLOW:
----------------------------------------------------------------------------------------------------
   - Creation:
     * Step 1: Allocate dynamic memory for `head`, set `head->data = A[0]`, `head->prev = NULL`, `head->next = NULL`.
     * Step 2: Track end of list using `last = head`.
     * Step 3: Loop through array: create node `t`, set `t->data = A[i]`, `t->next = NULL`, `t->prev = last`, 
       link `last->next = t`, update `last = t`.
   - Forward Display:
     * Traverse `p = head` while `p != NULL` using `p = p->next`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Creation Time Complexity  : O(n)
   - Display Time Complexity   : O(n)
   - Auxiliary Space Complexity: O(1)
====================================================================================================
*/

#include <iostream>
using namespace std;

// Doubly Linked List Node Structure
struct Node {
    Node* prev;
    int data;
    Node* next;
};

// Global Head Pointer
Node* head = NULL;

// Function to Create Doubly Linked List from Array
void create(int A[], int n) {
    if (n <= 0) return;

    // Step 1: Create Head Node
    head = new Node();
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;

    Node* last = head; // Tracking pointer

    // Step 2: Create Remaining Nodes
    for (int i = 1; i < n; i++) {
        Node* t = new Node();
        t->data = A[i];
        t->next = NULL;
        t->prev = last;     // Point new node back to current last
        last->next = t;     // Link current last to new node
        last = t;           // Move tracking pointer
    }
}

// Function to Display Doubly Linked List (Forward)
void display(Node* p) {
    while (p != NULL) {
        cout << p->data << " <-> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "--- Doubly Linked List: Creation & Display ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Doubly Linked List
    create(A, n);

    // Display Elements
    cout << "\nDoubly Linked List Elements: ";
    display(head);

    return 0;
}