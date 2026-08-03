/*
Program Name: Linked List - Reversing a Linked List (Iterative & Recursive)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Reversing a linked list changes the direction of pointers so the tail becomes the new head.
   - Reversing Links (Sliding Pointers method) is done in-place without extra dynamic memory allocation.

2. ALGORITHMIC FLOW (Sliding Pointers):
----------------------------------------------------------------------------------------------------
   - Maintain 3 pointers: `p` (scans list), `q` (follows `p`), `r` (follows `q`).
   - Initialize: `p = head`, `q = NULL`, `r = NULL`.
   - Traverse `while (p != NULL)`:
     * `r = q;`
     * `q = p;`
     * `p = p->next;` (Slide all 3 pointers forward)
     * `q->next = r;`  (Reverse connection link)
   - Update `head = q;`

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) (Single linear pass).
   - Space Complexity : O(1) Auxiliary space (In-place reversal).
====================================================================================================
*/

#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* next;
};

// Function to Create Linked List from Array
Node* create(int A[], int n) {
    if (n <= 0) return NULL;

    Node* head = new Node();
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
    return head;
}

// Function to Display Linked List
void display(Node* p) {
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Function to Reverse Linked List using Sliding Pointers
Node* reverseLinks(Node* head) {
    Node* p = head;
    Node* q = NULL;
    Node* r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next; // Slide pointers forward
        q->next = r;  // Reverse link direction
    }

    head = q; // Make last node the new head
    return head;
}

int main() {
    cout << "--- Linked List: Reverse List (Sliding Pointers) ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List
    Node* head = create(A, n);

    cout << "\nOriginal List : ";
    display(head);

    // Reverse Linked List
    head = reverseLinks(head);

    cout << "Reversed List : ";
    display(head);

    return 0;
}