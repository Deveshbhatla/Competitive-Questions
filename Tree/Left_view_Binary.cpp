
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
void leftview(Node *root)
{
      queue<Node*> q;
  
    if (root == NULL) 
        return; 
    q.push(root); 
    q.push(NULL); //as a delimiter
    while (!q.empty())
   { 
        Node* temp = q.front(); 

        if (temp!=0) 
        { 
            cout<<temp->key<<" ";//prints first node of each level
            // Push children of all nodes at current level 
            while (q.front() != NULL) 
            { 

                if (temp->left) 
                    q.push(temp->left); 

                if (temp->right) 
                    q.push(temp->right); 

                  q.pop(); 

                temp = q.front(); 
            } 
            // Push delimiter for the next level 
            q.push(NULL); 
        } 
        // Pop the delimiter of the previous level 
        q.pop(); 
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
	
	leftview(root);
}