/*
Program Name: Binary Search Tree (BST) - Iterative and Recursive Search


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Searching in a BST leverages the ordering invariant to discard half of the tree at each step.
   - Compares target key:
     * If key == node->data -> Element Found.
     * If key < node->data  -> Search Left Subtree.
     * If key > node->data  -> Search Right Subtree.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Iterative Search: Loop while pointer != NULL and update pointer to left or right child.
   - Recursive Search: Base condition (NULL or match), otherwise return recursive call on left/right.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(h) where h is height of BST (O(log n) average, O(n) worst case).
   - Space Complexity : O(1) for iterative search, O(h) stack frames for recursive search.
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

// BST Search Class
class BSTSearch {
private:
    Node* root;

    // Helper for Recursive Search
    Node* searchRecursiveHelper(Node* p, int key) {
        if (p == NULL || p->data == key) {
            return p;
        }
        if (key < p->data) {
            return searchRecursiveHelper(p->lchild, key);
        }
        return searchRecursiveHelper(p->rchild, key);
    }

public:
    BSTSearch() {
        root = NULL;
    }

    // Helper method to populate tree for search demonstration
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

    // Iterative Search
    bool searchIterative(int key) {
        Node* t = root;
        while (t != NULL) {
            if (key == t->data) {
                return true;
            } else if (key < t->data) {
                t = t->lchild;
            } else {
                t = t->rchild;
            }
        }
        return false;
    }

    // Recursive Search Interface
    bool searchRecursive(int key) {
        return searchRecursiveHelper(root, key) != NULL;
    }
};

int main() {
    cout << "--- Binary Search Tree (BST) Search Operations ---" << endl;

    BSTSearch bst;

    // Construct BST
    int dataset[] = {35, 15, 55, 10, 25, 45, 65};
    for (int x : dataset) {
        bst.insert(x);
    }

    // Test Iterative Search
    int target1 = 25;
    int target2 = 90;

    cout << "1. Iterative Search:" << endl;
    cout << "   - Searching for " << target1 << ": " 
         << (bst.searchIterative(target1) ? "Found in BST" : "Not Found") << endl;
    cout << "   - Searching for " << target2 << ": " 
         << (bst.searchIterative(target2) ? "Found in BST" : "Not Found") << endl;

    // Test Recursive Search
    int target3 = 45;
    int target4 = 12;

    cout << "\n2. Recursive Search:" << endl;
    cout << "   - Searching for " << target3 << ": " 
         << (bst.searchRecursive(target3) ? "Found in BST" : "Not Found") << endl;
    cout << "   - Searching for " << target4 << ": " 
         << (bst.searchRecursive(target4) ? "Found in BST" : "Not Found") << endl;

    return 0;
}