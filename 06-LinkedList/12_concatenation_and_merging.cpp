/*
Program Name: Linked List - Concatenation and Merging


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Concatenation: Attaching the head of List 2 to the end (NULL pointer) of List 1.
   - Merging: Combining two pre-sorted lists into a single sorted list by linking existing nodes.

2. ALGORITHMIC FLOW (Merging):
----------------------------------------------------------------------------------------------------
   - Step 1: Compare initial nodes of List 1 (`p`) and List 2 (`q`).
   - Set `third` and `last` to the node with the smaller value.
   - Advance the pointer of the chosen list.
   - Step 2: Loop while `p != NULL && q != NULL`:
     * If `p->data < q->data`: `last->next = p; last = p; p = p->next;`
     * Else: `last->next = q; last = q; q = q->next;`
   - Step 3: Attach remaining elements:
     * If `p != NULL`: `last->next = p;`
     * If `q != NULL`: `last->next = q;`

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Concatenation Time Complexity : O(n) [where n is length of List 1]
   - Merging Time Complexity       : O(m + n) [Linear time traversal]
   - Auxiliary Space Complexity    : O(1) [In-place pointer restructuring]
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

// Function to Merge Two Sorted Linked Lists
Node* merge(Node* p, Node* q) {
    Node* third = NULL;
    Node* last = NULL;

    if (p == NULL) return q;
    if (q == NULL) return p;

    // Initialize third and last pointers
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    // Merge loop
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    // Attach remaining elements
    if (p != NULL) last->next = p;
    if (q != NULL) last->next = q;

    return third;
}

int main() {
    cout << "--- Linked List: Merging Sorted Lists ---" << endl;

    int A[] = {10, 30, 50, 70};
    int B[] = {20, 40, 60, 80};

    // Create Two Sorted Lists
    Node* head1 = create(A, 4);
    Node* head2 = create(B, 4);

    cout << "\nList 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    // Merge Lists
    Node* mergedHead = merge(head1, head2);

    cout << "\nMerged Sorted List: ";
    display(mergedHead);

    return 0;
}