/*
Program Name: Linked List - Finding Middle Element (Slow and Fast Pointer Approach)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Finding the middle node of a linked list in a single linear pass using two pointers 
     moving at different speeds (Slow and Fast Pointers / Tortoise and Hare method).

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Initialize two pointers: `p = head` (Slow pointer) and `q = head` (Fast pointer).
   - Traverse `while (q != NULL && q->next != NULL)`:
     * Move slow pointer 1 step  : `p = p->next;`
     * Move fast pointer 2 steps : `q = q->next->next;`
   - When fast pointer reaches the end of the list, slow pointer `p` will be standing at the 
     exact middle node. Return `p->data`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) (Single linear scan).
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

// Function to Find Middle Element using Two Pointers (Slow & Fast)
int findMiddle(Node* p) {
    if (p == NULL) return -1;

    Node* slow = p; // Moves 1 step at a time
    Node* fast = p; // Moves 2 steps at a time

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps
    }

    return slow->data; // Slow pointer points to middle node
}

int main() {
    cout << "--- Linked List: Finding Middle Element ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List (Odd length)
    create(A, n);

    cout << "\nLinked List Elements: ";
    display(head);

    // Find and display middle element
    int midVal = findMiddle(head);
    cout << "Middle Element Value : " << midVal << endl;

    return 0;
}