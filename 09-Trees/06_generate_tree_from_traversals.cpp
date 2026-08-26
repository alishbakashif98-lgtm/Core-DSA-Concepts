/*
Program Name: Binary Tree - Generation from Preorder and Inorder Traversals


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Reconstructs a unique Binary Tree using given Preorder and Inorder traversal sequences.
   - Preorder identifies the root nodes sequentially.
   - Inorder partitions elements into respective left and right subtrees.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Pick next element from Preorder using a static/global index tracker.
   - Allocate new node with this data.
   - If start == end, return node (leaf node reached).
   - Find element index in Inorder array:
     * Recursively build left child with Inorder range [start, splitIndex - 1].
     * Recursively build right child with Inorder range [splitIndex + 1, end].

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n^2) using linear search in Inorder array (optimizable to O(n) via Hash Map).
   - Space Complexity : O(h) recursion call stack memory.
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

// Binary Tree Builder Class
class BinaryTreeBuilder {
private:
    TreeNode* root;
    int preIndex;

    // Helper to search element position in Inorder array
    int searchInorder(int inOrderArr[], int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (inOrderArr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // Recursive Tree Construction Engine
    TreeNode* buildTree(int preOrderArr[], int inOrderArr[], int inStart, int inEnd) {
        if (inStart > inEnd) {
            return NULL;
        }

        // Pick current node from Preorder traversal using preIndex
        int currVal = preOrderArr[preIndex++];
        TreeNode* node = new TreeNode();
        node->data = currVal;
        node->lchild = node->rchild = NULL;

        // If node has no children
        if (inStart == inEnd) {
            return node;
        }

        // Find index of node in Inorder traversal
        int splitIndex = searchInorder(inOrderArr, inStart, inEnd, currVal);

        // Recursively construct left and right subtrees
        node->lchild = buildTree(preOrderArr, inOrderArr, inStart, splitIndex - 1);
        node->rchild = buildTree(preOrderArr, inOrderArr, splitIndex + 1, inEnd);

        return node;
    }

    // Traversal Helpers for verification
    void postOrder(TreeNode* p) {
        if (p != NULL) {
            postOrder(p->lchild);
            postOrder(p->rchild);
            cout << p->data << " ";
        }
    }

    void inOrder(TreeNode* p) {
        if (p != NULL) {
            inOrder(p->lchild);
            cout << p->data << " ";
            inOrder(p->rchild);
        }
    }

public:
    BinaryTreeBuilder() {
        root = NULL;
        preIndex = 0;
    }

    void constructTree(int preOrderArr[], int inOrderArr[], int totalNodes) {
        preIndex = 0;
        root = buildTree(preOrderArr, inOrderArr, 0, totalNodes - 1);
    }

    void displayPostOrder() {
        cout << "Reconstructed Tree Post-order : ";
        postOrder(root);
        cout << endl;
    }

    void displayInOrder() {
        cout << "Reconstructed Tree In-order   : ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    cout << "--- Binary Tree Generation from Traversals ---" << endl;

    // Sample traversals
    // Tree Structure:
    //         4
    //       /   \
    //      7     9
    //       \   / \
    //        6 10  2
    int preOrderArr[] = {4, 7, 6, 9, 10, 2};
    int inOrderArr[]  = {7, 6, 4, 10, 9, 2};
    int totalNodes = sizeof(preOrderArr) / sizeof(preOrderArr[0]);

    cout << "Given Pre-order: ";
    for (int i = 0; i < totalNodes; i++) cout << preOrderArr[i] << " ";
    cout << "\nGiven In-order : ";
    for (int i = 0; i < totalNodes; i++) cout << inOrderArr[i] << " ";
    cout << "\n" << endl;

    BinaryTreeBuilder builder;
    builder.constructTree(preOrderArr, inOrderArr, totalNodes);

    cout << "--- Verification Traversals ---" << endl;
    builder.displayInOrder();
    builder.displayPostOrder();

    return 0;
}