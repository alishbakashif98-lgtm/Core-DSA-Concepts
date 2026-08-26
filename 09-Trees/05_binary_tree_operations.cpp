/*
Program Name: Binary Tree - Structural Operations and Metrics (Count, Height, Leaf Nodes, Sum)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Performs fundamental recursive properties and measurements on a Binary Tree:
     * Total node count
     * Tree height / depth
     * Leaf node count (Degree 0)
     * Non-leaf (internal) node count (Degree > 0)
     * Sum of all node values

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Count(p)       : count(left) + count(right) + 1
   - Height(p)      : max(height(left), height(right)) + 1
   - LeafCount(p)   : 1 if leaf node, else leafCount(left) + leafCount(right)
   - NonLeaf(p)     : 1 + nonLeaf(left) + nonLeaf(right) if internal, else nonLeaf(left) + nonLeaf(right)
   - Sum(p)         : sum(left) + sum(right) + p->data

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) for each metric (visits every node once).
   - Space Complexity : O(h) recursion stack frame space (h is height of tree).
====================================================================================================
*/

#include <iostream>
#include <algorithm>
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

    // Private Recursive Calculation Helpers
    int countNodes(TreeNode* p) {
        if (p == NULL) return 0;
        return countNodes(p->lchild) + countNodes(p->rchild) + 1;
    }

    int calculateHeight(TreeNode* p) {
        if (p == NULL) return 0;
        int x = calculateHeight(p->lchild);
        int y = calculateHeight(p->rchild);
        return max(x, y) + 1;
    }

    int countLeafNodes(TreeNode* p) {
        if (p == NULL) return 0;
        if (p->lchild == NULL && p->rchild == NULL) {
            return 1;
        }
        return countLeafNodes(p->lchild) + countLeafNodes(p->rchild);
    }

    int countNonLeafNodes(TreeNode* p) {
        if (p == NULL) return 0;
        if (p->lchild != NULL || p->rchild != NULL) {
            return countNonLeafNodes(p->lchild) + countNonLeafNodes(p->rchild) + 1;
        }
        return countNonLeafNodes(p->lchild) + countNonLeafNodes(p->rchild);
    }

    int sumNodes(TreeNode* p) {
        if (p == NULL) return 0;
        return sumNodes(p->lchild) + sumNodes(p->rchild) + p->data;
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

    // Public Wrapper Methods
    int countNodes() {
        return countNodes(root);
    }

    int calculateHeight() {
        return calculateHeight(root);
    }

    int countLeafNodes() {
        return countLeafNodes(root);
    }

    int countNonLeafNodes() {
        return countNonLeafNodes(root);
    }

    int sumNodes() {
        return sumNodes(root);
    }
};

int main() {
    cout << "--- Binary Tree Operations & Calculations ---" << endl;

    BinaryTree tree;
    tree.createTree();

    cout << "\n--- Tree Metrics & Calculations ---" << endl;
    cout << "Total Number of Nodes  : " << tree.countNodes() << endl;
    cout << "Height of Binary Tree  : " << tree.calculateHeight() << endl;
    cout << "Leaf Nodes (Degree 0)  : " << tree.countLeafNodes() << endl;
    cout << "Non-Leaf (Internal)    : " << tree.countNonLeafNodes() << endl;
    cout << "Sum of All Node Values : " << tree.sumNodes() << endl;

    return 0;
}