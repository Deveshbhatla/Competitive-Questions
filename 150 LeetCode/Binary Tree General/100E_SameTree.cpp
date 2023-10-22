//Given the roots of two binary trees p and q, write a function to check if they are the same or not.

//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


// https://leetcode.com/problems/same-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    
    // If only one tree is null or the values are different, they are not identical
    if (p == nullptr || q == nullptr || p->val != q->val)
    {
        return false;
    }
    // Recursively check if the left and right subtrees are identical
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    // Second level
    //  root->left->left=new TreeNode(NULL);
    //  root->left->right=new TreeNode(NULL);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << isSameTree(root,root);

    return 0;
}