// Given the root of a binary tree and an integer targetSum,
// return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.

// https://leetcode.com/problems/path-sum/

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
/**
 * Helper function for returning the sum of root to the node
 * return whether the sum of root to node equals the target sum
*/
bool rootToLeafSum(TreeNode *root, int targetSum, int sum)
{
    if(root==nullptr)
        return false;
    //if current node is leaf node(i.e it has no children), 
    //then means that you have reached the end of the tree    
    if(root->left==nullptr&&root->right==nullptr)
    {
        sum+=root->val;
        if(sum==targetSum)
            return true;
    }

    //while the current node is not leaf node, add the current node value to sum and return
    //with left and right parameters
    return rootToLeafSum(root->left,targetSum,sum+root->val)||
           rootToLeafSum(root->right,targetSum,sum+root->val);    
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    int sum=0;
    return rootToLeafSum(root,targetSum,sum);
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    // Second level
      root->left->left=new TreeNode(11);
      root->right->left=new TreeNode(13);
      root->right->right=new TreeNode(4);


    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right=new TreeNode(1);

    hasPathSum(root,22)?cout<<"true":cout<<"false";

    return 0;
}