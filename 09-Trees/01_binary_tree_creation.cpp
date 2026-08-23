/*
Program Name: Binary Tree - Level-Order Node Creation


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Dynamically constructs a Binary Tree level-by-level using a FIFO Queue of TreeNode pointers.
   - Encapsulates node management and tree construction inside a C++ class.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Read root node value, allocate memory, and enqueue root pointer.
   - While queue is not empty:
     * Dequeue parent pointer `p`.
     * Read left child value: if valid (!= -1), allocate child, link `p->lchild`, and enqueue child.
     * Read right child value: if valid (!= -1), allocate child, link `p->rchild`, and enqueue child.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) where n is total number of nodes created.
   - Space Complexity : O(n) Queue auxiliary space.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Tree Node Structure
struct TreeNode {
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
};

// Linked List Node for Pointer Queue
struct QueueNode {
    TreeNode* address;
    QueueNode* next;
};

// Queue Class to Store Tree Node Pointers
class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    ~Queue() {
        QueueNode* p = front;
        while (front != NULL) {
            front = front->next;
            delete p;
            p = front;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(TreeNode* x) {
        QueueNode* t = new QueueNode();
        if (t == NULL) return;
        t->address = x;
        t->next = NULL;

        if (isEmpty()) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }

    TreeNode* dequeue() {
        if (isEmpty()) return NULL;

        QueueNode* p = front;
        TreeNode* x = front->address;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete p;
        return x;
    }
};

// Binary Tree Class
class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() {
        root = NULL;
    }

    // Function to create binary tree level-by-level
    void createTree() {
        Queue q;
        TreeNode *p, *t;
        int x;

        cout << "Enter root value: ";
        cin >> x;
        root = new TreeNode();
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.enqueue(root);

        while (!q.isEmpty()) {
            p = q.dequeue();

            // Handle Left Child
            cout << "Enter left child of " << p->data << " (-1 for no node): ";
            cin >> x;
            if (x != -1) {
                t = new TreeNode();
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }

            // Handle Right Child
            cout << "Enter right child of " << p->data << " (-1 for no node): ";
            cin >> x;
            if (x != -1) {
                t = new TreeNode();
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }

    // Basic confirmation check
    void displayRoot() {
        if (root != NULL) {
            cout << "\nBinary Tree successfully created with Root: " << root->data << endl;
        } else {
            cout << "\nTree is empty!" << endl;
        }
    }
};

int main() {
    cout << "--- Binary Tree Creation ---" << endl;

    BinaryTree tree;
    tree.createTree();
    tree.displayRoot();

    return 0;
}