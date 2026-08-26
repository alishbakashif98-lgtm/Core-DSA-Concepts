/*
Program Name: Binary Tree - Iterative Traversals (Pre-order and In-order using Stack)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Implements non-recursive Depth-First Search (DFS) using an explicit pointer Stack.
   - Eliminates system call stack overhead while preserving standard traversal ordering.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Iterative Pre-order:
     * While t != NULL or !st.isEmpty():
       - If t != NULL: print t->data, push t to stack, move t = t->lchild.
       - Else: pop to t, move t = t->rchild.
   - Iterative In-order:
     * While t != NULL or !st.isEmpty():
       - If t != NULL: push t to stack, move t = t->lchild.
       - Else: pop to t, print t->data, move t = t->rchild.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) where n is total number of nodes.
   - Space Complexity : O(h) explicit Stack auxiliary space (where h is height of tree).
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

// Stack Node Structure
struct StackNode {
    TreeNode* address;
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
        StackNode* p = top;
        while (top != NULL) {
            top = top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(TreeNode* x) {
        StackNode* t = new StackNode();
        if (t == NULL) return;
        t->address = x;
        t->next = top;
        top = t;
    }

    TreeNode* pop() {
        if (isEmpty()) return NULL;

        StackNode* p = top;
        TreeNode* x = top->address;
        top = top->next;
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

    // Iterative Pre-order Traversal
    void iterativePreOrder() {
        Stack st;
        TreeNode* t = root;
        cout << "Iterative Pre-order Traversal: ";

        while (t != NULL || !st.isEmpty()) {
            if (t != NULL) {
                cout << t->data << " ";
                st.push(t);
                t = t->lchild;
            } else {
                t = st.pop();
                t = t->rchild;
            }
        }
        cout << endl;
    }

    // Iterative In-order Traversal
    void iterativeInOrder() {
        Stack st;
        TreeNode* t = root;
        cout << "Iterative In-order Traversal : ";

        while (t != NULL || !st.isEmpty()) {
            if (t != NULL) {
                st.push(t);
                t = t->lchild;
            } else {
                t = st.pop();
                cout << t->data << " ";
                t = t->rchild;
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Binary Tree Iterative Traversals ---" << endl;

    BinaryTree tree;
    tree.createTree();

    cout << "\n--- Traversal Outputs ---" << endl;
    tree.iterativePreOrder();
    tree.iterativeInOrder();

    return 0;
}