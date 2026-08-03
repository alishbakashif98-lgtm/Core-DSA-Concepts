/*
Program Name: Linked List - Check for Loop (Floyd's Cycle Detection)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A loop occurs when a node's `next` pointer points back to a previous node in the list.
   - Floyd’s Cycle Detection Algorithm uses two pointers moving at different speeds (Slow and Fast).

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Initialize two pointers: `p = head` (Slow, 1 step) and `q = head` (Fast, 2 steps).
   - Loop `while (q != NULL && q->next != NULL)`:
     * `p = p->next;`
     * `q = q->next->next;`
     * If `p == q`: Loop detected! Return `true`.
   - If loop terminates (reaches NULL): Return `false` (Linear List).

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n)
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

// Function to Check if List Has a Loop (Floyd's Cycle Finding Algorithm)
bool isLoop(Node* f) {
    Node* p = f; // Slow pointer (1 step)
    Node* q = f; // Fast pointer (2 steps)

    do {
        p = p->next;
        q = q ? q->next : NULL;
        q = q ? q->next : NULL;
    } while (p && q && p != q);

    return (p && q && p == q);
}

int main() {
    cout << "--- Linked List: Loop Detection ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linear Linked List
    Node* head = create(A, n);

    cout << "\nLinear List: ";
    display(head);

    if (isLoop(head)) {
        cout << "Result: Loop Detected in Linear List!" << endl;
    } else {
        cout << "Result: No Loop (Linear List)" << endl;
    }

    // Creating a Loop manually (Connecting last node '50' to node '30')
    Node* t1 = head->next->next; // Points to 30
    Node* t2 = head;
    while (t2->next != NULL) {
        t2 = t2->next; // Traverse to last node (50)
    }
    t2->next = t1; // 50 now points back to 30

    cout << "\nChecking again after creating a loop (50 -> 30)..." << endl;
    if (isLoop(head)) {
        cout << "Result: Loop Detected!" << endl;
    } else {
        cout << "Result: No Loop" << endl;
    }

    return 0;
}