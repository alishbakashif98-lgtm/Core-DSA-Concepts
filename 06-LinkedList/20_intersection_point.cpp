/*
Program Name: Linked List - Finding Intersection Point of Two Lists


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Identify the exact node memory address where two separate linked lists merge into a single tail.
   - We utilize two LIFO stacks to trace nodes backward from the end to find the divergence point.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Step 1: Push node pointers of List 1 onto `s1`.
   - Step 2: Push node pointers of List 2 onto `s2`.
   - Step 3: Maintain `intersectionNode = NULL`.
   - Step 4: Loop while `!s1.empty() && !s2.empty() && s1.top() == s2.top()`:
     * `intersectionNode = s1.top();`
     * `s1.pop();`
     * `s2.pop();`
   - Step 5: Return `intersectionNode`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(m + n) (Where m and n are lengths of both lists).
   - Space Complexity : O(m + n) (For auxiliary stacks).
====================================================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* next;
};

// Function to Display Linked List
void display(Node* p) {
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Function to Find Intersection Point using Stacks
Node* findIntersection(Node* head1, Node* head2) {
    stack<Node*> s1;
    stack<Node*> s2;

    // Push List 1 nodes to stack 1
    Node* p = head1;
    while (p != NULL) {
        s1.push(p);
        p = p->next;
    }

    // Push List 2 nodes to stack 2
    p = head2;
    while (p != NULL) {
        s2.push(p);
        p = p->next;
    }

    Node* intersection = NULL;

    // Pop and compare until nodes mismatch
    while (!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
        intersection = s1.top();
        s1.pop();
        s2.pop();
    }

    return intersection;
}

int main() {
    cout << "--- Linked List: Intersection Point of Two Lists ---" << endl;

    // 1. Create Shared Common Tail (30 -> 40 -> NULL)
    Node* common = new Node{30, new Node{40, NULL}};

    // 2. Create First Head (10 -> 20 -> [30 -> 40])
    Node* head1 = new Node{10, new Node{20, common}};

    // 3. Create Second Head (5 -> [30 -> 40])
    Node* head2 = new Node{5, common};

    cout << "\nList 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    // Find intersection
    Node* result = findIntersection(head1, head2);

    if (result != NULL) {
        cout << "\nIntersection Node Found!" << endl;
        cout << "Intersection Node Data: " << result->data << endl;
        cout << "Intersection Memory Address: " << result << endl;
    } else {
        cout << "\nNo Intersection Point Found!" << endl;
    }

    return 0;
}