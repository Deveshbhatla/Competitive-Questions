//The diameter of a tree (also called the width) is the number of nodes on the longest path between two end nodes.
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};
int height(Node* root, int& ans)
{
    if (root == NULL)
        return 0;
 
    int left_height = height(root->left, ans);
 
    int right_height = height(root->right, ans);
 
    //diameter of at ree is maximum value of (left_height + right_height + 1) for each node
    ans = max(ans, 1 + left_height + right_height);
 
    return 1 + max(left_height, right_height);
}
 
int diameter(Node* root)
{
    if (root == NULL)
        return 0;
    int ans = INT_MIN; // This will store the final answer
    height(root, ans);
    return ans;
}
int main()
{
    Node *root=new Node(2);
	root->left=new Node(8);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(5);
	
	cout<<diameter(root);
}