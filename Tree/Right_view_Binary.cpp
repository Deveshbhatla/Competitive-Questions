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
void rightview(Node *root)
{
      queue<Node*> q;
  
    if (root == NULL) 
        return; 
    q.push(root); 
    while (!q.empty())
   { 
        int n = q.size(); 
           for(int i = 1; i <= n; i++) 
        { 
            Node* temp = q.front(); 
            q.pop(); 
                  
            // Print the right most element at that level 
            if (i == n) 
                cout<<temp->key<<" "; 
              
            if (temp->left != NULL) 
                q.push(temp->left); 
  
            if (temp->right != NULL) 
                q.push(temp->right); 
        }
    } 
}

int main()
{
/*	 2
    / \
   8   3
      / \
     4   5*/
    Node *root=new Node(2);
	root->left=new Node(8);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(5);
	
	rightview(root);
}