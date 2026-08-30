/*
Program Name: AVL Tree - Node Deletion and Self-Rebalancing Rotations


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Deletes a target key from an AVL Tree and restores balance factor invariants (|BF| <= 1).
   - Rebalances ancestor subtrees using LL, RR, LR, and RL rotations upon recursive return.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Recursively search for target node.
   - Delete node using leaf removal, single child bypass, or predecessor/successor replacement.
   - Update current node height: height = max(hl, hr) + 1.
   - Check Balance Factor:
     * If BF == 2 and BF(left) >= 0   -> LL Rotation (R0 or R1 rotation).
     * If BF == 2 and BF(left) == -1  -> LR Rotation (R-1 rotation).
     * If BF == -2 and BF(right) <= 0 -> RR Rotation (L0 or L-1 rotation).
     * If BF == -2 and BF(right) == 1 -> RL Rotation (L1 rotation).

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(log n) guaranteed for deletion and all rebalancing steps.
   - Space Complexity : O(log n) recursive call stack frames.
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

// AVL Tree Deletion Class
class AVLTreeDeletion {
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

    // Helper: In-order Predecessor
    Node* inPredecessor(Node* p) {
        while (p && p->rchild != NULL) {
            p = p->rchild;
        }
        return p;
    }

    // Helper: In-order Successor
    Node* inSuccessor(Node* p) {
        while (p && p->lchild != NULL) {
            p = p->lchild;
        }
        return p;
    }

    // Rotations
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

    // Recursive Insertion
    Node* recursiveInsert(Node* p, int key) {
        if (p == NULL) {
            Node* t = new Node();
            t->data = key;
            t->height = 1;
            t->lchild = t->rchild = NULL;
            return t;
        }

        if (key < p->data) {
            p->lchild = recursiveInsert(p->lchild, key);
        } else if (key > p->data) {
            p->rchild = recursiveInsert(p->rchild, key);
        } else {
            return p;
        }

        p->height = nodeHeight(p);

        if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) return LLRotation(p);
        if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) return RRRotation(p);
        if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) return LRRotation(p);
        if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) return RLRotation(p);

        return p;
    }

    // Recursive Deletion Engine with Rebalancing
    Node* recursiveDelete(Node* p, int key) {
        if (p == NULL) return NULL;

        // Leaf node base case
        if (p->lchild == NULL && p->rchild == NULL) {
            if (p == root) root = NULL;
            delete p;
            return NULL;
        }

        // Search Phase
        if (key < p->data) {
            p->lchild = recursiveDelete(p->lchild, key);
        } else if (key > p->data) {
            p->rchild = recursiveDelete(p->rchild, key);
        } else {
            // Node found: Replace with Predecessor or Successor
            if (nodeHeight(p->lchild) > nodeHeight(p->rchild)) {
                Node* q = inPredecessor(p->lchild);
                p->data = q->data;
                p->lchild = recursiveDelete(p->lchild, q->data);
            } else {
                Node* q = inSuccessor(p->rchild);
                p->data = q->data;
                p->rchild = recursiveDelete(p->rchild, q->data);
            }
        }

        // Update height
        p->height = nodeHeight(p);

        // Rebalancing checks
        // L Rotations (Left heavy)
        if (balanceFactor(p) == 2 && balanceFactor(p->lchild) >= 0) {
            return LLRotation(p);
        } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
            return LRRotation(p);
        }
        // R Rotations (Right heavy)
        else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) <= 0) {
            return RRRotation(p);
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
    AVLTreeDeletion() {
        root = NULL;
    }

    void insert(int key) {
        root = recursiveInsert(root, key);
    }

    void remove(int key) {
        root = recursiveDelete(root, key);
    }

    void displayInOrder() {
        cout << "AVL In-order [Val(Height)]: ";
        inOrder(root);
        cout << endl;
    }

    void displayRoot() {
        if (root) {
            cout << "Root: " << root->data << " (Tree Height: " << root->height << ")" << endl;
        } else {
            cout << "Tree is Empty!" << endl;
        }
    }
};

int main() {
    cout << "--- AVL Tree Node Deletion & Self-Rebalancing ---" << endl;

    AVLTreeDeletion avl;

    // Construct balanced AVL tree
    int dataset[] = {10, 20, 30, 25, 28, 27, 5};
    for (int x : dataset) {
        avl.insert(x);
    }

    cout << "Initial Tree:" << endl;
    avl.displayInOrder();
    avl.displayRoot();

    // 1. Delete node requiring balance adjustment
    cout << "\nDeleting 28..." << endl;
    avl.remove(28);
    avl.displayInOrder();
    avl.displayRoot();

    // 2. Delete Root node (25)
    cout << "\nDeleting Root Node (25)..." << endl;
    avl.remove(25);
    avl.displayInOrder();
    avl.displayRoot();

    return 0;
}