// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
// and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

/**
 * helper function for building tree
 */
TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder,
                          int inorderStart, int inorderEnd, int postorderStart, int postorderEnd,
                          unordered_map<int, int> &index)
{
    if (inorderStart > inorderEnd || postorderStart > postorderEnd)
        return nullptr;

    int rootValue = postorder[postorderEnd];
    TreeNode *root = new TreeNode(rootValue);

    int inorderRootIndex = index[rootValue];
    int leftSubtreeSize = inorderRootIndex - inorderStart;

    root->left = buildTreeHelper(inorder, postorder, inorderStart, inorderRootIndex - 1, postorderStart, postorderStart + leftSubtreeSize - 1, index);
    root->right = buildTreeHelper(inorder, postorder, inorderRootIndex + 1, inorderEnd, postorderStart + leftSubtreeSize, postorderEnd - 1, index);

    return root;
}
/**
 * build tree
 */
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> index;
    for (int i = 0; i < inorder.size(); i++)
        index[inorder[i]] = i;

    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0,
                           postorder.size() - 1, index);
}
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
    vector<int> preorder = {9, 3, 15, 20, 7};
    vector<int> inorder = {9, 15, 7, 20, 3};

    print2DUtil(buildTree(preorder, inorder), 0);

    return 0;
}