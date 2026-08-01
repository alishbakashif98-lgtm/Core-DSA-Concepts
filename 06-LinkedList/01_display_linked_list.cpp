/*
Program Name: Linked List - Basic Creation and Iterative Display


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Linked List is a linear chain of dynamic structures called Nodes.
   - Each Node contains two parts:
     1. `data`: Holds the value.
     2. `next`: Pointer storing the memory address of the next Node.

2. STEP-BY-STEP CREATION FLOW:
----------------------------------------------------------------------------------------------------
   - Step 1 [First Node]: Allocate heap memory for `head`, set `head->data = A[0]`, `head->next = NULL`.
   - Step 2 [Tracking Pointer]: Maintain `last` pointer pointing to `head`.
   - Step 3 [Linking Loop]: Loop through array from index 1 to n-1:
     * Allocate new node `t` on heap.
     * Set `t->data = A[i]` and `t->next = NULL`.
     * Attach new node to current end: `last->next = t`.
     * Move tracking pointer: `last = t`.

3. DISPLAY FLOW (TRAVERSAL):
----------------------------------------------------------------------------------------------------
   - Set temporary pointer `p = head`.
   - Loop `while (p != NULL)`:
     * Print `p->data`.
     * Move pointer to next node: `p = p->next`.

4. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Creation Time Complexity : O(n)
   - Display Time Complexity  : O(n)
   - Auxiliary Space Complexity: O(1)
====================================================================================================
*/

#include <iostream>
using namespace std;

// 1. Basic Node Structure
struct Node {
    int data;
    Node* next;
};

// Global Head Pointer
Node* head = NULL;

// Function to Create Linked List from Array
void create(int A[], int n) {
    if (n <= 0) return;

    // Step 1: Create First (Head) Node
    head = new Node();
    head->data = A[0];
    head->next = NULL;

    Node* last = head; // 'last' always points to the end node

    // Step 2: Create rest of the nodes
    for (int i = 1; i < n; i++) {
        Node* t = new Node(); // Allocate new node in Heap
        t->data = A[i];
        t->next = NULL;

        last->next = t; // Connect previous node to new node
        last = t;       // Move 'last' to the new node
    }
}

// Function to Display Linked List
void display(Node* p) {
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next; // Move to next node
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "--- Simple Linked List Creation & Display ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List
    create(A, n);

    // Display Linked List
    cout << "\nLinked List Elements: ";
    display(head);

    return 0;
}