/*
Program Name: Binary Search Tree (BST) - Recursive Node Deletion


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Deletion removes a targeted key while preserving BST ordering invariants:
     * Leaf node deletion (0 children).
     * Single child deletion (link parent to child).
     * Two children deletion (replace with In-order Predecessor/Successor based on subtree height).

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Recursively search down to target key.
   - If key found:
     * If leaf node: delete and return NULL.
     * If height(left) > height(right): replace key with In-order Predecessor and delete predecessor.
     * Else: replace key with In-order Successor and delete successor.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(h) where h is tree height (O(log n) balanced, O(n) skewed).
   - Space Complexity : O(h) recursive call stack space.
====================================================================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

// BST Node Structure
struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

// BST Deletion Class
class BSTDeletion {
private:
    Node* root;

    // Helper: Calculate Subtree Height
    int calculateHeight(Node* p) {
        if (p == NULL) return 0;
        int x = calculateHeight(p->lchild);
        int y = calculateHeight(p->rchild);
        return max(x, y) + 1;
    }

    // Helper: Find In-order Predecessor (Rightmost node in Left Subtree)
    Node* inPredecessor(Node* p) {
        while (p && p->rchild != NULL) {
            p = p->rchild;
        }
        return p;
    }

    // Helper: Find In-order Successor (Leftmost node in Right Subtree)
    Node* inSuccessor(Node* p) {
        while (p && p->lchild != NULL) {
            p = p->lchild;
        }
        return p;
    }

    // Recursive Deletion Engine
    Node* deleteNode(Node* p, int key) {
        if (p == NULL) return NULL;

        // Leaf node base case
        if (p->lchild == NULL && p->rchild == NULL) {
            if (p == root) root = NULL;
            delete p;
            return NULL;
        }

        // Search Phase
        if (key < p->data) {
            p->lchild = deleteNode(p->lchild, key);
        } else if (key > p->data) {
            p->rchild = deleteNode(p->rchild, key);
        } else {
            // Target Node Found: Decide whether to use Predecessor or Successor based on height
            if (calculateHeight(p->lchild) > calculateHeight(p->rchild)) {
                Node* q = inPredecessor(p->lchild);
                p->data = q->data;
                p->lchild = deleteNode(p->lchild, q->data);
            } else {
                Node* q = inSuccessor(p->rchild);
                p->data = q->data;
                p->rchild = deleteNode(p->rchild, q->data);
            }
        }
        return p;
    }

    // In-order traversal helper
    void inOrder(Node* p) {
        if (p != NULL) {
            inOrder(p->lchild);
            cout << p->data << " ";
            inOrder(p->rchild);
        }
    }

public:
    BSTDeletion() {
        root = NULL;
    }

    void insert(int key) {
        Node* t = root;
        Node* r = NULL;
        Node* p;

        if (root == NULL) {
            p = new Node();
            p->data = key;
            p->lchild = p->rchild = NULL;
            root = p;
            return;
        }

        while (t != NULL) {
            r = t;
            if (key == t->data) return;
            else if (key < t->data) t = t->lchild;
            else t = t->rchild;
        }

        p = new Node();
        p->data = key;
        p->lchild = p->rchild = NULL;

        if (key < r->data) r->lchild = p;
        else r->rchild = p;
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    void displayInOrder() {
        cout << "BST In-order: ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    cout << "--- Binary Search Tree (BST) Node Deletion ---" << endl;

    BSTDeletion bst;

    // Populate initial BST
    int dataset[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : dataset) {
        bst.insert(x);
    }

    cout << "Initial ";
    bst.displayInOrder();

    // 1. Delete Leaf Node (20)
    cout << "\nDeleting Leaf Node (20)..." << endl;
    bst.remove(20);
    bst.displayInOrder();

    // 2. Delete Node with Children (30)
    cout << "\nDeleting Node with Child (30)..." << endl;
    bst.remove(30);
    bst.displayInOrder();

    // 3. Delete Root Node (50)
    cout << "\nDeleting Root Node (50)..." << endl;
    bst.remove(50);
    bst.displayInOrder();

    return 0;
}