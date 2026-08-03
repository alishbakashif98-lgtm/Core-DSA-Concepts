/*
Program Name: Linked List - Remove Duplicates from Sorted List


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Scan a sorted linked list and remove contiguous duplicate values.
   - Since the list is sorted, all identical elements appear sequentially adjacent to each other.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Use two adjacent pointers: `p` (current node) and `q` (next node, `q = p->next`).
   - Loop while `q != NULL`:
     * If `p->data == q->data` (Duplicate found):
       - Bypass `q`: `p->next = q->next`
       - Delete `q`: `delete q`
       - Update `q`: `q = p->next`
     * Else (Unique element):
       - Advance both pointers: `p = q`, `q = q->next`

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) (Single linear traversal).
   - Space Complexity : O(1) Auxiliary space.
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

// Function to Remove Duplicates from Sorted List
void removeDuplicates(Node* p) {
    if (p == NULL) return;

    Node* q = p->next; // q points to the node right after p

    while (q != NULL) {
        if (p->data == q->data) {
            p->next = q->next; // Bypass duplicate node q
            delete q;          // Deallocate memory
            q = p->next;       // Re-assign q to new adjacent node
        } else {
            p = q;
            q = q->next;       // Advance both pointers
        }
    }
}

int main() {
    cout << "--- Linked List: Remove Duplicates ---" << endl;

    int A[] = {10, 20, 20, 30, 40, 40, 40, 50};
    int n = 8;

    // Create Linked List
    Node* head = create(A, n);

    cout << "\nInitial List with Duplicates: ";
    display(head);

    // Remove duplicates
    removeDuplicates(head);

    cout << "List after Removing Duplicates: ";
    display(head);

    return 0;
}