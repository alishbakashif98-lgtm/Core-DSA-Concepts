/*
Program Name: AVL Tree - Insertion and Self-Balancing Rotations (LL, RR, LR, RL)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - An AVL Tree is a self-balancing Binary Search Tree where the height difference (Balance Factor)
     between left and right subtrees cannot exceed 1 for any node.
   - Restores balance via 4 standard tree rotations: LL, RR, LR, RL.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Recursive BST insertion.
   - Update node height at each return step.
   - Compute Balance Factor (BF = height(left) - height(right)).
   - If BF == 2 and BF(left) == 1   -> Perform LL Rotation.
   - If BF == -2 and BF(right) == -1 -> Perform RR Rotation.
   - If BF == 2 and BF(left) == -1  -> Perform LR Rotation.
   - If BF == -2 and BF(right) == 1  -> Perform RL Rotation.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(log n) guaranteed for Search, Insert, and Balance.
   - Space Complexity : O(log n) recursion call stack memory.
====================================================================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

// AVL Node Structure
struct Node {
    int data;
    int height;
    Node* lchild;
    Node* rchild;
};

// AVL Tree Class
class AVLTree {
private:
    Node* root;

    // Helper: Node Height Safe Getter
    int nodeHeight(Node* p) {
        int hl = (p && p->lchild) ? p->lchild->height : 0;
        int hr = (p && p->rchild) ? p->rchild->height : 0;
        return max(hl, hr) + 1;
    }

    // Helper: Balance Factor Calculation
    int balanceFactor(Node* p) {
        int hl = (p && p->lchild) ? p->lchild->height : 0;
        int hr = (p && p->rchild) ? p->rchild->height : 0;
        return hl - hr;
    }

    // 1. LL Rotation (Single Right Rotation)
    Node* LLRotation(Node* p) {
        Node* pl = p->lchild;
        Node* plr = pl->rchild;

        pl->rchild = p;
        p->lchild = plr;

        p->height = nodeHeight(p);
        pl->height = nodeHeight(pl);

        if (root == p) root = pl;
        return pl;
    }

    // 2. RR Rotation (Single Left Rotation)
    Node* RRRotation(Node* p) {
        Node* pr = p->rchild;
        Node* prl = pr->lchild;

        pr->lchild = p;
        p->rchild = prl;

        p->height = nodeHeight(p);
        pr->height = nodeHeight(pr);

        if (root == p) root = pr;
        return pr;
    }

    // 3. LR Rotation (Double Rotation: Left then Right)
    Node* LRRotation(Node* p) {
        Node* pl = p->lchild;
        Node* plr = pl->rchild;

        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;

        plr->lchild = pl;
        plr->rchild = p;

        pl->height = nodeHeight(pl);
        p->height = nodeHeight(p);
        plr->height = nodeHeight(plr);

        if (root == p) root = plr;
        return plr;
    }

    // 4. RL Rotation (Double Rotation: Right then Left)
    Node* RLRotation(Node* p) {
        Node* pr = p->rchild;
        Node* prl = pr->lchild;

        pr->lchild = prl->rchild;
        p->rchild = prl->lchild;

        prl->rchild = pr;
        prl->lchild = p;

        pr->height = nodeHeight(pr);
        p->height = nodeHeight(p);
        prl->height = nodeHeight(prl);

        if (root == p) root = prl;
        return prl;
    }

    // Recursive AVL Insertion Engine
    Node* recursiveInsert(Node* p, int key) {
        if (p == NULL) {
            Node* t = new Node();
            t->data = key;
            t->height = 1; // Leaf node height is 1
            t->lchild = t->rchild = NULL;
            return t;
        }

        if (key < p->data) {
            p->lchild = recursiveInsert(p->lchild, key);
        } else if (key > p->data) {
            p->rchild = recursiveInsert(p->rchild, key);
        } else {
            return p; // Duplicates ignored
        }

        // Update height of ancestor node
        p->height = nodeHeight(p);

        // Check Balance Factor & Perform Suitable Rotation
        if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {
            return LLRotation(p);
        } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) {
            return RRRotation(p);
        } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
            return LRRotation(p);
        } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) {
            return RLRotation(p);
        }

        return p;
    }

    // In-order traversal helper
    void inOrder(Node* p) {
        if (p != NULL) {
            inOrder(p->lchild);
            cout << p->data << "(H:" << p->height << ") ";
            inOrder(p->rchild);
        }
    }

public:
    AVLTree() {
        root = NULL;
    }

    void insert(int key) {
        root = recursiveInsert(root, key);
    }

    void displayInOrder() {
        cout << "AVL In-order [Val(Height)]: ";
        inOrder(root);
        cout << endl;
    }

    void displayRoot() {
        if (root) {
            cout << "Balanced Root Node: " << root->data << " (Tree Height: " << root->height << ")" << endl;
        }
    }
};

int main() {
    cout << "--- AVL Tree Self-Balancing Insertions ---" << endl;

    AVLTree avl;

    // Inserting keys causing LL, RR, LR rotations
    int keys[] = {10, 20, 30, 25, 28, 27, 5};
    cout << "Inserting keys: ";
    for (int k : keys) {
        cout << k << " ";
        avl.insert(k);
    }
    cout << "\n\n";

    avl.displayInOrder();
    avl.displayRoot();

    return 0;
}