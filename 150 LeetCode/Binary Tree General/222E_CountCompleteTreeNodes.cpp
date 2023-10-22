//Given the root of a complete binary tree, return the number of the nodes in the tree.
//According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
//It can have between 1 and 2h nodes inclusive at the last level h.
//Design an algorithm that runs in less than O(n) time complexity.


//https://leetcode.com/problems/count-complete-tree-nodes/

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

int countNodes(TreeNode*root)
{
    if(root==nullptr)
        return 0;
    
    //return how many times you traversed the nodes and +1 for root node
    return countNodes(root->left)+countNodes(root->right)+1;     
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

    cout<<countNodes(root);

    return 0;
}