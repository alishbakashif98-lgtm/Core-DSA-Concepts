/*
Program Name: Doubly Linked List - Insertion and Deletion Operations


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Inserting and deleting nodes in a Doubly Linked List requires updating both `prev` and `next` 
     pointers of surrounding nodes to maintain two-way connectivity.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Insertion (pos = 0):
     * Set `t->prev = NULL; t->next = head;`
     * If `head != NULL`, set `head->prev = t;`
     * Update `head = t;`
   - Insertion (pos > 0):
     * Move `p` to `pos - 1`.
     * Set `t->next = p->next; t->prev = p;`
     * If `p->next != NULL`, set `p->next->prev = t;`
     * Set `p->next = t;`
   - Deletion (pos = 1):
     * Move `head = head->next;`
     * If `head != NULL`, set `head->prev = NULL;`
     * Free memory of target head node.
   - Deletion (pos > 1):
     * Move `p` to target position `pos`.
     * `p->prev->next = p->next;`
     * If `p->next != NULL`, `p->next->prev = p->prev;`
     * Free memory: `delete p;`

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(1) at Head, O(k) at position k.
   - Space Complexity : O(1) Auxiliary space.
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

// Function to Count Nodes in Doubly Linked List
int count(Node* p) {
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Function to Insert Node in Doubly Linked List
void insert(int pos, int x) {
    if (pos < 0 || pos > count(head)) return;

    Node* t = new Node();
    t->data = x;

    // Case 1: Insert at Head (pos = 0)
    if (pos == 0) {
        t->prev = NULL;
        t->next = head;
        if (head != NULL) {
            head->prev = t;
        }
        head = t;
    } 
    // Case 2: Insert at position pos > 0
    else {
        Node* p = head;
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if (p->next != NULL) {
            p->next->prev = t;
        }
        p->next = t;
    }
}

// Function to Delete Node from Doubly Linked List
int deleteNode(int pos) {
    if (pos < 1 || pos > count(head)) return -1;

    int x = -1;
    Node* p = head;

    // Case 1: Delete Head Node (pos = 1)
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        x = p->data;
        delete p;
    } 
    // Case 2: Delete at position pos > 1
    else {
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }

    return x;
}

int main() {
    cout << "--- Doubly Linked List: Insert & Delete Operations ---" << endl;

    int A[] = {10, 20, 30, 40};
    int n = 4;

    create(A, n);

    cout << "\nInitial Doubly List: ";
    display(head);

    // Insert 5 at Head
    cout << "\nInserting 5 at Head (pos 0)..." << endl;
    insert(0, 5);
    display(head);

    // Insert 25 at position 3
    cout << "\nInserting 25 at position 3..." << endl;
    insert(3, 25);
    display(head);

    // Delete Head Node
    cout << "\nDeleting Head Node (pos 1)..." << endl;
    int deletedVal = deleteNode(1);
    cout << "Deleted Value: " << deletedVal << endl;
    display(head);

    return 0;
}