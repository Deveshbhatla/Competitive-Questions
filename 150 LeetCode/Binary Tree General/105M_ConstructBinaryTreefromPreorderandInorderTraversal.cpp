// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and
// inorder is the inorder traversal of the same tree, construct and return the binary tree.

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

int preorderIndex;
unordered_map<int, int> inorderIndexMap;

/**
 * helper tree function for building tree
 * takes preorder vector, left index an right index of the preorder traversal
*/
TreeNode *buildTreeHelper(vector<int> &preorder, int left, int right)
{
    if (left > right)
        return nullptr;
    int rootValue = preorder[preorderIndex++];
    TreeNode *root = new TreeNode(rootValue);
    int inorderPivotIndex = inorderIndexMap[rootValue];
    // think about it..why I am choosing root -> left first then root -> right
    root->left = buildTreeHelper(preorder, left, inorderPivotIndex - 1);
    root->right = buildTreeHelper(preorder, inorderPivotIndex + 1, right);
    return root;
}

/**
 * builds the map of Inorder index with key as the inorder vector value, and the value as the index
 * 
*/
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    preorderIndex = 0;
    
    //filling the map of inorder tree with key as element and value as its index
    for (int i = 0; i < inorder.size(); i++)
    {
        inorderIndexMap[inorder[i]] = i;
    
    }
    return buildTreeHelper(preorder, 0, preorder.size() - 1);
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    print2DUtil(buildTree(preorder, inorder), 0);

    return 0;
}