#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left,*right; 
  Node(int k)
  {
      key=k;
      left=right=NULL;
  }
};
//Reccursive Insert
Node *Reccursive_insert(Node *root, int element)//Time O(h), space O(1)
{
    if(root==NULL)
        return new Node(element);
    if(root->key<element)
        root->right=Reccursive_insert(root->right,element);//to link the two nodes
    else if(root->key>element)
        root->left=Reccursive_insert(root->left,element);//to link the two nodes
    return root;
} 

//Iterative Insert 
Node *Iterative_insert(Node *root, int element)// Time O(h), space O(1)
{
    Node *temp=new Node(element);
    Node *parent=NULL;//parent node, 
    Node *curr=root;

    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key>element)
            curr=curr->left;
        else if(curr->key<element)
            curr=curr->right;
        else
            return root;
    }
    if(parent==NULL)//if tree is empty
        return temp;

    if(parent->key>element)
        parent->left=temp;
    else
        parent->right=temp;
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
	int x=81;
	
	root=Reccursive_insert(root,x);
	inorder(root);
}