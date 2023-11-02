// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.
//     1
//   /   \
// 2       3

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.



//https://leetcode.com/problems/sum-root-to-leaf-numbers/
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

void sumToLeaf(TreeNode *root, int &sum, int num)
{
    if (!root)
        return;

    // Forming the number
    num = num * 10 + root->val;

    if (root->left == nullptr && root->right == nullptr)
    {
        sum += num; // actual sum, passed by reference
        return;
    }
    sumToLeaf(root->left, sum, num);
    sumToLeaf(root->right, sum, num);
}

int sumNumbers(TreeNode *root)
{
    int sum = 0, num = 0;
    sumToLeaf(root, sum, num);
    return sum;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << sumNumbers(root);
    return 0;
}