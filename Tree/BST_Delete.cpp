#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k)
  {
      key=k;
      left=right=NULL;
  }
};
Node *getSuccessor(Node *curr) // Closest greater value. To get inoder successor for the case where both the children are non-empty. 
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}

Node *delNode(Node *root, int x)//O(h) time and space
{
    if(root==NULL)
        return root;
        //same as insert
    if(root->key>x)
        root->left=delNode(root->left,x);
    else if(root->key<x)
        root->right=delNode(root->right,x);

        //3 cases: leaf node, one child is present and both childs are present 
    else
    {   
        if(root->left==NULL)//when left is empty, right can be either empty or non empty. It can also handle when both the children are empty
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)//when right is empty, left can be either empty or non empty. It can also handle when both the children are empty
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }

        else// when both the left and right child are empty
        {
            Node *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
} 

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
} 
int main() 
{
/*
        15
       / \
      5   20
     /   / \
    3   18  80
       /
      16  */
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=15;
	
	root=delNode(root,x);
	inorder(root);
}