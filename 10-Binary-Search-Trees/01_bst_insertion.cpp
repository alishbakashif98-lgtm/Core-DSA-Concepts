/*
Program Name: Binary Search Tree (BST) - Node Insertion and In-Order Traversal


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Binary Search Tree insertion maintains the ordering property:
     * Values smaller than current node go to Left Subtree.
     * Values greater than current node go to Right Subtree.
     * Duplicate values are ignored.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Start from root with pointer `t` and trailing parent pointer `r`.
   - Traverse down comparing key with `t->data` until `t` hits NULL.
   - Allocate new node and attach to `r->lchild` or `r->rchild`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(h) where h is height of the BST (O(log n) average, O(n) worst case).
   - Space Complexity : O(1) auxiliary space for iterative insertion.
====================================================================================================
*/

#include <iostream>
using namespace std;

// BST Node Structure
struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

// BST Insertion Class
class BSTInsertion {
private:
    Node* root;

    // Helper for In-Order Traversal (Sorted order)
    void inOrder(Node* p) {
        if (p != NULL) {
            inOrder(p->lchild);
            cout << p->data << " ";
            inOrder(p->rchild);
        }
    }

public:
    BSTInsertion() {
        root = NULL;
    }

    // Iterative BST Insertion
    void insert(int key) {
        Node* t = root;
        Node* r = NULL;
        Node* p;

        // Base case: If tree is empty
        if (root == NULL) {
            p = new Node();
            p->data = key;
            p->lchild = p->rchild = NULL;
            root = p;
            return;
        }

        // Search for appropriate leaf position
        while (t != NULL) {
            r = t;
            if (key == t->data) {
                cout << "Key " << key << " already exists (Duplicates not allowed)." << endl;
                return;
            } else if (key < t->data) {
                t = t->lchild;
            } else {
                t = t->rchild;
            }
        }

        // Allocate and link new node
        p = new Node();
        p->data = key;
        p->lchild = p->rchild = NULL;

        if (key < r->data) {
            r->lchild = p;
        } else {
            r->rchild = p;
        }
    }

    // Display In-Order traversal
    void displaySorted() {
        cout << "BST In-order (Sorted Sequence): ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    cout << "--- Binary Search Tree (BST) Insertion ---" << endl;

    BSTInsertion bst;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    cout << "Inserting values: ";
    for (int val : values) {
        cout << val << " ";
        bst.insert(val);
    }
    cout << "\n\n";

    bst.displaySorted();

    return 0;
}