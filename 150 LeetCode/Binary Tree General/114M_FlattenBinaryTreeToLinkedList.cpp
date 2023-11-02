// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

    TreeNode *prev = nullptr;

public:
    /**
     * Flatten
     */
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

// helper function to print the tree
void print2DUtil(TreeNode *root, int indent)
{
    if (root == NULL)
        return;

    // Increase distance between levels
    indent += COUNT;

    // Process right child first
    print2DUtil(root->right, indent);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < indent; i++)
        cout << " ";
    cout << root->val << "\n";

    // Process left child
    print2DUtil(root->left, indent);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Second level
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(7);

    // print2DUtil(flatten(root), 0);

    Solution sol;
    sol.flatten(root);

    return 0;
}