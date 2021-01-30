#include<bits/stdc++.h>
using namespace std;
struct Node 
{
    int key;
    Node *left,*right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};
//Recursive approach
int recursive_search(Node *root,int element)//time O(h) space O(h)
{
    if(root==NULL)
        return 0;
    else if(root->key==element)
        return element;
    else if(root->key>element)
        return recursive_search(root->left,element);
    else
    return recursive_search(root->right,element);    

}
//Iterative implementation
int Iterative_search(Node *root,int element)//time O(h) space O(1)
{
    while(root!=NULL)
    {
        if(root->key==element)
            return element;
        else if(root->key>element)
            root=root->left;
        else
            root=root->right;    
    }
    return 0;
}
int main()
{/*
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
	int x=90;
    // if(recursive_search(root,x))
    //      cout<<recursive_search(root,x);
    // else
    //     cout<<"Not Found";


 if(Iterative_search(root,x))
         cout<<Iterative_search(root,x);
    else
        cout<<"Not Found";
}