// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
// A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

int max_sum = INT_MIN;
int max_gain(TreeNode *root)
{
    if (!root)
        return 0;
    int left = max(max_gain(root->left), 0);
    int right = max(max_gain(root->right), 0);

    int new_price = root->val + left + right;
    max_sum = max(max_sum, new_price);

    return root->val + max(left, right);
}
/**
 * Solved using DFS
 */
int maxPathSum(TreeNode *root)
{
    max_gain(root);
    return max_sum;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << maxPathSum(root);
    return 0;
}
