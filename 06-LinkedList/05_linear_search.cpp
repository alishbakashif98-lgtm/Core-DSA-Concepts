/*
Program Name: Linked List - Linear Search and Move to Head Optimization


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Linear Search scans the list sequentially from head to NULL.
   - Move to Head Optimization: When an element is found, it is shifted to the head position so that
     subsequent searches for the same element execute in O(1) time.

2. ALGORITHMIC FLOW (Move to Head):
----------------------------------------------------------------------------------------------------
   - Maintain `p` (current pointer) and `q` (tail pointer following `p`).
   - If `p->data == key`:
     * If `p` is already `head`, simply return `p`.
     * Otherwise: `q->next = p->next` (Bypass `p`).
     * `p->next = head` (Point `p` to current head).
     * `head = p` (Make `p` the new head).

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Standard Linear Search : O(n) Time | O(1) Space
   - Move to Head Optimized : O(n) Worst case first search, O(1) Best/Subsequent searches.
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

// 1. Standard Linear Search
Node* search(Node* p, int key) {
    while (p != NULL) {
        if (key == p->data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 2. Optimized Linear Search (Move to Head)
Node* searchMoveToHead(Node* p, int key) {
    Node* q = NULL; // Previous pointer tracking behind p

    while (p != NULL) {
        if (key == p->data) {
            // Move to Head logic (only if element is not already at head)
            if (p != head) {
                q->next = p->next; // Bypass p
                p->next = head;    // Move p to start
                head = p;          // Update head
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main() {
    cout << "--- Linked List: Linear Search & Move to Head ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List
    create(A, n);

    cout << "\nInitial Linked List: ";
    display(head);

    // Perform Search for element 40
    int key = 40;
    cout << "\nSearching for " << key << " using Move-to-Head..." << endl;
    Node* temp = searchMoveToHead(head, key);

    if (temp) {
        cout << "Element " << temp->data << " found in memory!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    // Display List after search to verify element moved to head
    cout << "List after searching " << key << ": ";
    display(head);

    return 0;
}