/*
Program Name: Linked List - Recursive Display (Forward & Reverse)


1. RECURSIVE DISPLAY MECHANICS:
----------------------------------------------------------------------------------------------------
   - Forward Display: Print `p->data` BEFORE the recursive call (Calling Phase).
   - Reverse Display: Print `p->data` AFTER the recursive call (Returning/Unwinding Phase).

2. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n)
   - Space Complexity : O(n) [Call Stack Memory]
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

// Function to Create Linked List
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

// 1. Recursive Display (Forward)
void displayForward(Node* p) {
    if (p != NULL) {
        cout << p->data << " -> "; // Pehle print hoga
        displayForward(p->next);   // Phir agle node par jaye ga
    }
}

// 2. Recursive Display (Reverse)
void displayReverse(Node* p) {
    if (p != NULL) {
        displayReverse(p->next);   // Pehle aakhri node tak jaye ga
        cout << p->data << " -> "; // Wapsi par print kare ga
    }
}

int main() {
    cout << "--- Linked List: Recursive Display ---" << endl;

    int A[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Create Linked List
    create(A, n);

    // Forward Display
    cout << "\nForward Display: ";
    displayForward(head);
    cout << "NULL" << endl;

    // Reverse Display
    cout << "Reverse Display: ";
    displayReverse(head);
    cout << "NULL" << endl;

    return 0;
}