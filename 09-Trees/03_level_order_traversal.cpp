/*
Program Name: Binary Tree - Level Order Traversal (BFS)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Level Order Traversal visits nodes level-by-level from top to bottom and left to right.
   - Operates as a Breadth-First Search (BFS) using a FIFO pointer Queue.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Print root node data and enqueue root address.
   - While queue is not empty:
     * Dequeue pointer `p`.
     * If `p->lchild` exists: print left child data and enqueue `p->lchild`.
     * If `p->rchild` exists: print right child data and enqueue `p->rchild`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) where n is total number of nodes (each node visited once).
   - Space Complexity : O(w) Queue memory where w is maximum width of tree (up to O(n)).
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

// Queue Node for Tree Pointers
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

public:
    BinaryTree() {
        root = NULL;
    }

    // Dynamic Tree Creation
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

    // Level-order Traversal (BFS)
    void levelOrder() {
        Queue q;
        cout << "Level-order Traversal: ";
        if (root == NULL) return;

        cout << root->data << " ";
        q.enqueue(root);

        while (!q.isEmpty()) {
            TreeNode* p = q.dequeue();

            if (p->lchild != NULL) {
                cout << p->lchild->data << " ";
                q.enqueue(p->lchild);
            }

            if (p->rchild != NULL) {
                cout << p->rchild->data << " ";
                q.enqueue(p->rchild);
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Binary Tree Level Order Traversal ---" << endl;

    BinaryTree tree;
    tree.createTree();

    cout << "\n--- Traversal Output ---" << endl;
    tree.levelOrder();

    return 0;
}