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

int getSize(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return 1+getSize(root->left)+getSize(root->right);
} 

int main() 
{
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->right=new Node(6);
	root->left->left->left=new Node(7);

	cout<<getSize(root);
}