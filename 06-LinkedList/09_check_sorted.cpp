/*
Program Name: Linked List - Check if List is Sorted


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Verify whether all elements in the linked list are in non-decreasing (ascending) order.
   - Maintain a tracker variable `x` initialized to `INT_MIN`.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Initialize `x = INT_MIN`.
   - Traverse through the list using pointer `p`:
     * If `p->data < x`, return `false` (List is unsorted).
     * Set `x = p->data`.
     * Move `p = p->next`.
   - If traversal completes without violation, return `true` (List is sorted).

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) (Single linear scan).
   - Space Complexity : O(1) Auxiliary space.
====================================================================================================
*/

#include <iostream>
#include <climits> // For INT_MIN
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

// Function to Check if Linked List is Sorted
bool isSorted(Node* p) {
    int x = INT_MIN; // Set tracker to minimum integer

    while (p != NULL) {
        if (p->data < x) {
            return false; // Violation found
        }
        x = p->data; // Update tracker
        p = p->next; // Move to next node
    }
    return true; // List is sorted
}

int main() {
    cout << "--- Linked List: Check if Sorted ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int B[] = {10, 25, 15, 40, 50};

    // Create List 1 (Sorted)
    Node* head1 = create(A, 5);
    cout << "\nList 1: ";
    display(head1);
    if (isSorted(head1)) {
        cout << "Result: List 1 is Sorted!" << endl;
    } else {
        cout << "Result: List 1 is NOT Sorted!" << endl;
    }

    // Create List 2 (Unsorted)
    Node* head2 = create(B, 5);
    cout << "\nList 2: ";
    display(head2);
    if (isSorted(head2)) {
        cout << "Result: List 2 is Sorted!" << endl;
    } else {
        cout << "Result: List 2 is NOT Sorted!" << endl;
    }

    return 0;
}