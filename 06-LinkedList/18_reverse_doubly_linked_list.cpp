/*
Program Name: Doubly Linked List - Reverse List


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Reversing a Doubly Linked List requires swapping the `next` and `prev` pointers for every node.
   - The head pointer is then updated to point to the former last node of the list.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Initialize pointer `p = head` and temporary pointer `temp = NULL`.
   - Loop while `p != NULL`:
     * Save `p->next` in `temp`.
     * Swap: `p->next = p->prev;`
     * Swap: `p->prev = temp;`
     * Move `p` forward using original link: `p = p->prev;`
     * Check: If `p != NULL` and `p->next == NULL`, update `head = p;`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) (Single linear pass).
   - Space Complexity : O(1) Auxiliary space (In-place reversal).
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

    head = new Node();
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;

    Node* last = head;

    for (int i = 1; i < n; i++) {
        Node* t = new Node();
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Function to Display Doubly Linked List
void display(Node* p) {
    while (p != NULL) {
        cout << p->data << " <-> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Function to Reverse Doubly Linked List
void reverse(Node* p) {
    Node* temp = NULL;

    while (p != NULL) {
        // Swap next and prev pointers
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        // Move to the next node in original sequence (which is now p->prev)
        p = p->prev;

        // If p reaches the end, update head to the last non-null node
        if (p != NULL && p->next == NULL) {
            head = p;
        }
    }
}

int main() {
    cout << "--- Doubly Linked List: Reverse List ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Doubly Linked List
    create(A, n);

    cout << "\nOriginal List : ";
    display(head);

    // Reverse List
    reverse(head);

    cout << "Reversed List : ";
    display(head);

    return 0;
}