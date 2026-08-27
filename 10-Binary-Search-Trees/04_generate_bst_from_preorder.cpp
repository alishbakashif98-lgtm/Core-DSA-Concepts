/*
Program Name: Binary Search Tree (BST) - Generation from Preorder Traversal


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Reconstructs a complete Binary Search Tree strictly from its Preorder traversal sequence.
   - Utilizes a pointer Stack to track potential parent nodes during descent and ascent.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Create root from pre[0], push to Stack, set p = root.
   - For each subsequent element pre[i]:
     * If pre[i] < p->data:
       - Allocate node, attach to p->lchild, push p to stack, update p = t.
     * Else (pre[i] > p->data):
       - If pre[i] is within valid parent upper bound:
         - Pop from stack while pre[i] > stackTop->data to find immediate parent.
         - Allocate node, attach to p->rchild, update p = t.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) as each element is pushed and popped from stack at most once.
   - Space Complexity : O(h) auxiliary Stack space where h is tree height.
====================================================================================================
*/

#include <iostream>
#include <climits>
using namespace std;

// BST Node Structure
struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

// Stack Node for Node Pointers
struct StackNode {
    Node* address;
    StackNode* next;
};

// Pointer Stack Class
class Stack {
private:
    StackNode* top;

public:
    Stack() {
        top = NULL;
    }

    ~Stack() {
        StackNode* p = frontNode();
        while (top != NULL) {
            top = top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    StackNode* frontNode() {
        return top;
    }

    void push(Node* x) {
        StackNode* t = new StackNode();
        if (t == NULL) return;
        t->address = x;
        t->next = top;
        top = t;
    }

    Node* pop() {
        if (isEmpty()) return NULL;

        StackNode* p = top;
        Node* x = top->address;
        top = top->next;
        delete p;
        return x;
    }

    Node* stackTop() {
        if (isEmpty()) return NULL;
        return top->address;
    }
};

// BST Generator Class
class BSTFromPreorder {
private:
    Node* root;

    // Helper for In-order verification (Must output sorted sequence)
    void inOrder(Node* p) {
        if (p != NULL) {
            inOrder(p->lchild);
            cout << p->data << " ";
            inOrder(p->rchild);
        }
    }

public:
    BSTFromPreorder() {
        root = NULL;
    }

    // O(n) Stack-based BST Generation Engine
    void generateFromPreorder(int pre[], int n) {
        if (n <= 0) return;

        Stack st;
        int i = 0;

        // Step 1: Initialize Root
        root = new Node();
        root->data = pre[i++];
        root->lchild = root->rchild = NULL;

        Node* p = root;

        // Step 2: Iterate through remaining Preorder elements
        while (i < n) {
            // Case 1: Left Child Condition
            if (pre[i] < p->data) {
                Node* t = new Node();
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                st.push(p);
                p = t;
            }
            // Case 2: Right Child Condition
            else {
                int upperLimit = (!st.isEmpty()) ? st.stackTop()->data : INT_MAX;
                if (pre[i] > p->data && pre[i] < upperLimit) {
                    Node* t = new Node();
                    t->data = pre[i++];
                    t->lchild = t->rchild = NULL;
                    p->rchild = t;
                    p = t;
                } else {
                    p = st.pop();
                }
            }
        }
    }

    // Display In-order traversal
    void displayInOrder() {
        cout << "Generated BST In-order (Sorted): ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    cout << "--- Generate BST from Preorder Traversal ---" << endl;

    // Given Preorder Traversal
    int preorder[] = {30, 20, 10, 15, 25, 40, 50};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    cout << "Given Preorder Sequence: ";
    for (int i = 0; i < n; i++) {
        cout << preorder[i] << " ";
    }
    cout << "\n\n";

    BSTFromPreorder bstBuilder;
    bstBuilder.generateFromPreorder(preorder, n);

    // Verify reconstruction using In-order traversal
    bstBuilder.displayInOrder();

    return 0;
}