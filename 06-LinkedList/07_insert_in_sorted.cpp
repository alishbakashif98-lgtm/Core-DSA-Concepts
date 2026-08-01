/*
Program Name: Linked List - Insertion in a Sorted Linked List


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Inserting an element `x` into an already sorted linked list such that the list remains sorted.
   - We scan the list using two pointers: `p` (current) and `q` (tailing pointer).

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Step 1: Allocate new node `t`, set `t->data = x`, `t->next = NULL`.
   - Step 2: Handle empty list case: If `head == NULL`, set `head = t`.
   - Step 3: Traverse while `p != NULL && p->data < x`:
     * `q = p;`
     * `p = p->next;`
   - Step 4:
     * If `p == head` (element is smaller than first node), insert at front: `t->next = head; head = t;`.
     * Otherwise, insert between `q` and `p`: `t->next = q->next; q->next = t;`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) worst-case (inserting at end), O(1) best-case (inserting at front).
   - Space Complexity : O(1) auxiliary space.
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

// Function to Display Linked List
void display(Node* p) {
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Function to Insert into a Sorted Linked List
void insertSorted(Node* p, int x) {
    Node* t = new Node();
    t->data = x;
    t->next = NULL;

    Node* q = NULL; // Previous pointer

    // Case 1: Empty List
    if (head == NULL) {
        head = t;
        return;
    }

    // Traverse to find the correct sorted position
    while (p != NULL && p->data < x) {
        q = p;
        p = p->next;
    }

    // Case 2: Element is smaller than head (Insert at beginning)
    if (p == head) {
        t->next = head;
        head = t;
    } 
    // Case 3: Insert between q and p (or at the end)
    else {
        t->next = q->next;
        q->next = t;
    }
}

int main() {
    cout << "--- Linked List: Insert in Sorted List ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Initial Sorted Linked List
    create(A, n);

    cout << "\nInitial Sorted List : ";
    display(head);

    // Insert elements in sorted order
    cout << "\nInserting 25 in sorted list..." << endl;
    insertSorted(head, 25);
    display(head);

    cout << "\nInserting 5 (smallest) in sorted list..." << endl;
    insertSorted(head, 5);
    display(head);

    cout << "\nInserting 60 (largest) in sorted list..." << endl;
    insertSorted(head, 60);
    display(head);

    return 0;
}