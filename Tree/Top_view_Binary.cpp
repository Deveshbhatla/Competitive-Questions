#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left,* right;
    int horizontal_distance; 

    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};
void topview(Node* root) 
{ 
    if(root==NULL) 
        return; 
    
    queue<Node*>q; 
    map<int,int> m; 
    int horizontal_distance=0; 

    root->horizontal_distance = horizontal_distance; 
    // push node and horizontal distance to queue 
    q.push(root); 
    cout<< "Top view of tree is: "; 
    while(q.size()) 
    { 
        horizontal_distance = root->horizontal_distance; 
        
        // Check if any node with this horizontal distance is encontered yet or not.
        // If not, insert current node's data to Map
        if(m.count(horizontal_distance)==0) 
            m[horizontal_distance]=root->key; 
        
        // Push the left child with its horizontal distance to queue
        if(root->left) 
        { 
            root->left->horizontal_distance=horizontal_distance-1; 
            q.push(root->left); 
        } 
        
        // Push the right child with its horizontal distance to queue        
        if(root->right) 
        { 
            root->right->horizontal_distance=horizontal_distance+1; 
            q.push(root->right); 
        } 
        
        q.pop(); 
        root=q.front(); 
    } 
    
    // Print the map as it stores the nodes appearing in the Top View
    for(auto i=m.begin();i!=m.end();i++) 
    { 
        cout<<i->second<<" "; 
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
	
	topview(root);
}