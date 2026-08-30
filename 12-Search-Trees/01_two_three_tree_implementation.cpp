/*
Program Name: 2-3 Search Tree - Insertion, Splitting, and Sorted Traversal


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A 2-3 Tree is a self-balancing multi-way search tree where every internal node has either:
     * 2 children (with 1 key) -> 2-Node
     * 3 children (with 2 keys) -> 3-Node
   - All leaf nodes exist at the exact same depth (perfect height balance).

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Search down to target leaf node.
   - Insert key into leaf:
     * If leaf had 1 key -> now has 2 keys (valid 3-node).
     * If leaf had 2 keys -> temporary overflow (3 keys). Split node:
       - Middle key promotes upward to parent.
       - Left key forms new left child; right key forms new right child.
     * Propagation continues upward; if root splits, new root is created (tree grows in height).

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(log n) guaranteed for Search, Insert, and Traversal.
   - Space Complexity : O(n) total node allocation.
====================================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2-3 Tree Node Structure
struct Node23 {
    vector<int> keys;
    vector<Node23*> children;
    bool isLeaf;

    Node23(bool leaf) {
        isLeaf = leaf;
    }
};

// 2-3 Search Tree Class
class TwoThreeTree {
private:
    Node23* root;

    // Helper: Split child node during upward insertion
    void splitChild(Node23* parent, int index, Node23* child) {
        Node23* rightSibling = new Node23(child->isLeaf);

        // Right sibling gets the rightmost key
        rightSibling->keys.push_back(child->keys[2]);

        // If not leaf, move rightmost 2 children to right sibling
        if (!child->isLeaf) {
            rightSibling->children.push_back(child->children[2]);
            rightSibling->children.push_back(child->children[3]);
            child->children.resize(2);
        }

        // Middle key (keys[1]) promotes to parent
        int promotedKey = child->keys[1];
        child->keys.resize(1); // Left child retains keys[0]

        // Insert promoted key into parent
        parent->keys.insert(parent->keys.begin() + index, promotedKey);
        parent->children.insert(parent->children.begin() + index + 1, rightSibling);
    }

    // Helper: Insert into a non-full node
    void insertNonFull(Node23* node, int key) {
        int i = node->keys.size() - 1;

        if (node->isLeaf) {
            node->keys.push_back(0);
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        } else {
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }
            i++;

            if (node->children[i]->keys.size() == 2) {
                insertNonFull(node->children[i], key);
                if (node->children[i]->keys.size() == 3) {
                    splitChild(node, i, node->children[i]);
                }
                return;
            }

            insertNonFull(node->children[i], key);
        }
    }

    // In-order traversal helper
    void inOrder(Node23* p) {
        if (p == NULL) return;

        int i;
        for (i = 0; i < p->keys.size(); i++) {
            if (!p->isLeaf) {
                inOrder(p->children[i]);
            }
            cout << p->keys[i] << " ";
        }

        if (!p->isLeaf) {
            inOrder(p->children[i]);
        }
    }

public:
    TwoThreeTree() {
        root = NULL;
    }

    void insert(int key) {
        if (root == NULL) {
            root = new Node23(true);
            root->keys.push_back(key);
            return;
        }

        insertNonFull(root, key);

        if (root->keys.size() == 3) {
            Node23* newRoot = new Node23(false);
            newRoot->children.push_back(root);
            splitChild(newRoot, 0, root);
            root = newRoot;
        }
    }

    void displayInOrder() {
        cout << "2-3 Tree In-order (Sorted): ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    cout << "--- 2-3 Multi-Way Search Tree ---" << endl;

    TwoThreeTree tree;

    int values[] = {30, 20, 40, 10, 25, 35, 50, 5, 15};
    cout << "Inserting elements: ";
    for (int v : values) {
        cout << v << " ";
        tree.insert(v);
    }
    cout << "\n\n";

    tree.displayInOrder();

    return 0;
}