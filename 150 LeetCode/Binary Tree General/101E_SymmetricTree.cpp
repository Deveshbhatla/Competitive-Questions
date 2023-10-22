// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// https://leetcode.com/problems/symmetric-tree/

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
//helper function
bool isMirror(TreeNode *left, TreeNode *right)
{
    if (!left && !right)//if both are null then they are mirror. return true
        return true;
    if (!left || !right)//if one of them is null, they are not mirror, return false
        return false;
        
    return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return isMirror(root->left, root->right);
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

    cout << isSymmetric(root);

    return 0;
}