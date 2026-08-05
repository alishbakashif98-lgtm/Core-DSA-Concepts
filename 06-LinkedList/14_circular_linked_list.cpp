/*
Program Name: Circular Linked List - Basic Creation and Traversal


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Circular Linked List is a linear dynamic data structure where the last node points back 
     to the head node instead of NULL.
   - It forms a continuous closed ring with no explicit NULL termination.

2. STEP-BY-STEP FLOW:
----------------------------------------------------------------------------------------------------
   - Creation:
     * Step 1: Allocate memory for `head`, set `head->data = A[0]` and `head->next = head`.
     * Step 2: Maintain tracking pointer `last = head`.
     * Step 3: Loop through array: allocate node `t`, set `t->next = last->next`, 
       link `last->next = t`, update `last = t`.
   - Display Traversal:
     * Use a `do-while` loop so the first node prints before checking the exit condition `p != head`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Creation Time Complexity  : O(n)
   - Display Time Complexity   : O(n)
   - Auxiliary Space Complexity: O(1)
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

// Function to Create Circular Linked List from Array
void create(int A[], int n) {
    if (n <= 0) return;

    // Step 1: Create First (Head) Node
    head = new Node();
    head->data = A[0];
    head->next = head; // Points to itself initially

    Node* last = head; // Tracking pointer

    // Step 2: Create remaining nodes
    for (int i = 1; i < n; i++) {
        Node* t = new Node();
        t->data = A[i];
        t->next = last->next; // Point new node to head
        last->next = t;       // Link previous node to new node
        last = t;             // Move last tracking pointer
    }
}

// Function to Display Circular Linked List
void display(Node* p) {
    if (p == NULL) return;

    do {
        cout << p->data << " -> ";
        p = p->next; // Move to next node
    } while (p != head); // Stop when we return to head

    cout << "(Head)" << endl;
}

int main() {
    cout << "--- Circular Linked List: Creation & Display ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Circular Linked List
    create(A, n);

    // Display Circular Linked List
    cout << "\nCircular List Elements: ";
    display(head);

    return 0;
}