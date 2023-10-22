// Given the root of a binary tree, invert the tree, and return its root.

// https://leetcode.com/problems/invert-binary-tree/

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
TreeNode *invertTree(TreeNode *root)
{
    if (root)
    {
        // swapping the left and right nodes
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}

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
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    print2DUtil(invertTree(root), 0);
    return 0;
}