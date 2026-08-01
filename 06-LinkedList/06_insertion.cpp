/*
Program Name: Linked List - Node Insertion Operations


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Inserting a new node into a linked list at position `pos` (0-based or 1-based indexing).
   - Case 1: `pos == 0` -> Insertion at the beginning (before Head).
   - Case 2: `pos > 0`  -> Insertion at a specified position after traversing `pos - 1` nodes.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Validate Position: Check if `pos` is valid (0 <= pos <= total_nodes).
   - Insert at Position 0:
     * `t = new Node(); t->data = x;`
     * `t->next = head; head = t;`
   - Insert at Position > 0:
     * Traverse `p` to position `pos - 1`.
     * `t = new Node(); t->data = x;`
     * `t->next = p->next; p->next = t;`

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Inserting at Head (pos = 0) : O(1) Time
   - Inserting at Position k     : O(k) Time
   - Space Complexity            : O(1) Auxiliary Space
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

// Function to Insert Node at a Given Position (1-based index for post-head nodes, 0 for head)
void insert(Node* p, int pos, int x) {
    // Validate position range
    if (pos < 0 || pos > count(p)) return;

    Node* t = new Node();
    t->data = x;

    // Case 1: Insert at the beginning (before Head)
    if (pos == 0) {
        t->next = head;
        head = t;
    } 
    // Case 2: Insert at position pos
    else {
        // Move p pointer to pos - 1 position
        for (int i = 0; i < pos - 1 && p != NULL; i++) {
            p = p->next;
        }

        if (p != NULL) {
            t->next = p->next; // Point new node to current next
            p->next = t;       // Link current node to new node
        }
    }
}

int main() {
    cout << "--- Linked List: Insertion Showcase ---" << endl;

    // Create Linked List purely using Insert function
    insert(head, 0, 10); // Insert 10 at pos 0 (Head)
    insert(head, 1, 20); // Insert 20 at pos 1
    insert(head, 2, 30); // Insert 30 at pos 2
    insert(head, 0, 5);  // Insert 5 at pos 0 (New Head)
    insert(head, 3, 25); // Insert 25 at pos 3

    cout << "\nLinked List After Insertions: ";
    display(head);

    return 0;
}