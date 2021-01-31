//Ceil Value Node: Node with smallest data larger than or equal to key value. Ceiling
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

Node *ceil(Node *root, int search_key)
{
    Node *result=NULL;
    while(root!=NULL)
    {
        if(root->key==search_key)
            return root;
        else if(root->key<search_key)
            root=root->right;
        else
        {
            result=root;
            root=root->left;
        }
    }
    return result;
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
	int x=17;
	
	cout<<"Ceil: "<<(ceil(root,17)->key);
}
