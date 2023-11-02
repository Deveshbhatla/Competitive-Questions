// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia:
// “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as
// descendants (where we allow a node to be a descendant of itself).”

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (right && left) // else we have found our LCA if left and tight are not null
        return root;
    else if (left) // if left!=null
        return left;
    else if (right) // if right!=null
        return right;
    else
        return nullptr;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *p = root->left = new TreeNode(5);
    TreeNode *q = root->right = new TreeNode(1);
    cout << lowestCommonAncestor(root, p, q)->val;
    return 0;
}