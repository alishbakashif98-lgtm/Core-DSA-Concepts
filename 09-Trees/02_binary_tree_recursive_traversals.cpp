/*
Program Name: Binary Tree - Recursive Traversals (Pre-order, In-order, Post-order)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Implements Depth-First Search (DFS) recursive traversals on a Binary Tree.
   - Visits every node exactly once using call stack recursion.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Pre-order (p)  : Print p->data -> Recurse Left -> Recurse Right
   - In-order (p)   : Recurse Left -> Print p->data -> Recurse Right
   - Post-order (p) : Recurse Left -> Recurse Right -> Print p->data

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) where n is total number of nodes.
   - Space Complexity : O(h) recursion stack frame space (where h is height of tree).
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

// Queue Node for Tree Generation
struct QueueNode {
    TreeNode* address;
    QueueNode* next;
};

// Pointer Queue Class
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

    // Private Recursive Helpers
    void preOrder(TreeNode* p) {
        if (p != NULL) {
            cout << p->data << " ";
            preOrder(p->lchild);
            preOrder(p->rchild);
        }
    }

    void inOrder(TreeNode* p) {
        if (p != NULL) {
            inOrder(p->lchild);
            cout << p->data << " ";
            inOrder(p->rchild);
        }
    }

    void postOrder(TreeNode* p) {
        if (p != NULL) {
            postOrder(p->lchild);
            postOrder(p->rchild);
            cout << p->data << " ";
        }
    }

public:
    BinaryTree() {
        root = NULL;
    }

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

            cout << "Enter left child of " << p->data << " (-1 for no node): ";
            cin >> x;
            if (x != -1) {
                t = new TreeNode();
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }

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

    // Public Interfaces
    void preOrder() {
        cout << "Pre-order Traversal  : ";
        preOrder(root);
        cout << endl;
    }

    void inOrder() {
        cout << "In-order Traversal   : ";
        inOrder(root);
        cout << endl;
    }

    void postOrder() {
        cout << "Post-order Traversal : ";
        postOrder(root);
        cout << endl;
    }
};

int main() {
    cout << "--- Binary Tree Recursive Traversals ---" << endl;

    BinaryTree tree;
    tree.createTree();

    cout << "\n--- Traversal Outputs ---" << endl;
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();

    return 0;
}