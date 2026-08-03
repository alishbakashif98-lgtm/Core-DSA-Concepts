/*
Program Name: Linked List - Node Deletion Operations


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Removing a node at a given position `pos` (1-based indexing) and deallocating its dynamic memory.
   - Return the deleted node's value for confirmation/verification.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Validate Position: Check if `pos >= 1 && pos <= count(p)`.
   - Case 1 (`pos == 1` - Delete Head):
     * Set `p = head;`
     * Move head: `head = head->next;`
     * Extract value `x = p->data;`
     * Free memory: `delete p;`
   - Case 2 (`pos > 1` - Delete internal or end node):
     * Traverse `p` to position `pos` and maintain `q` at position `pos - 1`.
     * Unlink: `q->next = p->next;`
     * Extract value `x = p->data;`
     * Free memory: `delete p;`

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Deleting Head (pos = 1) : O(1) Time
   - Deleting Position k      : O(k) Time
   - Space Complexity         : O(1) Auxiliary Space
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

// Function to Count Total Nodes
int count(Node* p) {
    int c = 0;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

// Function to Display Linked List
void display(Node* p) {
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Function to Delete Node at Position `pos` (1-based index)
int deleteNode(Node* p, int pos) {
    int x = -1; // Default return value if position invalid

    // Validate position range
    if (pos < 1 || pos > count(p)) return -1;

    // Case 1: Delete Head Node (pos == 1)
    if (pos == 1) {
        Node* t = head;
        x = head->data;
        head = head->next;
        delete t; // Free heap memory
        return x;
    }
    // Case 2: Delete at position pos > 1
    else {
        Node* q = NULL; // Previous pointer

        for (int i = 0; i < pos - 1 && p != NULL; i++) {
            q = p;
            p = p->next;
        }

        if (p != NULL) {
            q->next = p->next; // Bypass p node
            x = p->data;
            delete p; // Free heap memory
        }
        return x;
    }
}

int main() {
    cout << "--- Linked List: Deletion Operations ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List
    create(A, n);

    cout << "\nInitial Linked List: ";
    display(head);

    // Delete head node (Position 1)
    cout << "\nDeleting node at position 1 (Head)..." << endl;
    int deletedVal = deleteNode(head, 1);
    cout << "Deleted Value: " << deletedVal << endl;
    cout << "List after deletion: ";
    display(head);

    // Delete internal node (Position 3 -> element 40 in remaining list)
    cout << "\nDeleting node at position 3..." << endl;
    deletedVal = deleteNode(head, 3);
    cout << "Deleted Value: " << deletedVal << endl;
    cout << "List after deletion: ";
    display(head);

    return 0;
}