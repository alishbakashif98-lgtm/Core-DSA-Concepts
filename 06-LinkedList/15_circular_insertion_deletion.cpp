/*
Program Name: Circular Linked List - Insertion and Deletion Operations


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Performing node additions and removals while preserving the circular ring structure.
   - Modifying the head node always requires updating the last node's `next` pointer.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Insertion (pos = 0):
     * Allocate node `t`. Link `t->next = head`.
     * Traverse `p` to last node (`p->next == head`).
     * `p->next = t; head = t;`
   - Insertion (pos > 0):
     * Traverse `p` to `pos - 1`.
     * `t->next = p->next; p->next = t;`
   - Deletion (pos = 1):
     * Traverse `p` to last node (`p->next == head`).
     * `p->next = head->next; delete head; head = p->next;`
   - Deletion (pos > 1):
     * Traverse `p` to `pos - 2`, set `q = p->next`.
     * `p->next = q->next; delete q;`

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) for operations involving head or position k.
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

// Global Head Pointer
Node* head = NULL;

// Function to Create Circular Linked List
void create(int A[], int n) {
    if (n <= 0) return;

    head = new Node();
    head->data = A[0];
    head->next = head;

    Node* last = head;

    for (int i = 1; i < n; i++) {
        Node* t = new Node();
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Function to Display Circular Linked List
void display(Node* p) {
    if (p == NULL) return;

    do {
        cout << p->data << " -> ";
        p = p->next;
    } while (p != head);

    cout << "(Head)" << endl;
}

// Function to Count Nodes in Circular List
int count(Node* p) {
    if (p == NULL) return 0;
    int len = 0;
    do {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

// Function to Insert Node in Circular List
void insert(int pos, int x) {
    if (pos < 0 || pos > count(head)) return;

    Node* t = new Node();
    t->data = x;

    // Case 1: Insert at Head (pos = 0)
    if (pos == 0) {
        if (head == NULL) {
            head = t;
            head->next = head;
        } else {
            Node* p = head;
            while (p->next != head) {
                p = p->next; // Move to last node
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    } 
    // Case 2: Insert at position pos > 0
    else {
        Node* p = head;
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// Function to Delete Node from Circular List
int deleteNode(int pos) {
    if (pos < 1 || pos > count(head)) return -1;

    int x = -1;

    // Case 1: Delete Head Node (pos = 1)
    if (pos == 1) {
        Node* p = head;
        while (p->next != head) {
            p = p->next; // Move to last node
        }

        x = head->data;

        if (head == p) { // Only one node in list
            delete head;
            head = NULL;
        } else {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    } 
    // Case 2: Delete at position pos > 1
    else {
        Node* p = head;
        for (int i = 0; i < pos - 2; i++) {
            p = p->next;
        }
        Node* q = p->next; // Node to be deleted
        p->next = q->next;
        x = q->data;
        delete q;
    }

    return x;
}

int main() {
    cout << "--- Circular List: Insert & Delete Operations ---" << endl;

    int A[] = {10, 20, 30, 40};
    int n = 4;

    create(A, n);

    cout << "\nInitial Circular List: ";
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