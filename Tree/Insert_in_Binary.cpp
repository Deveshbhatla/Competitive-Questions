#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left,*right;
    //     Node(int k)
    // {
    //     key=k;
    //     left=right=NULL;
    // }
};

struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
void inorder(Node *temp)
{
    if(!temp)//same as if(temp==NULL)
        return;
    inorder(temp->left);
    cout<<temp->key;
    inorder(temp->right);

}

void insert(Node *temp, int key)
{
    queue<struct Node*>q;
    q.push(temp);
//Doing a level order traversal until an empty place is found
    while(!q.empty()) // while(q.empty==0), means queue is not empty
    {
        struct Node* temp=q.front();
        q.pop();

        if(!temp->left) //if(temp->left==NULL)
        {
            temp->left==newNode(key);
            break;
        }
        else
        {
            q.push(temp->left);
        }

        if(!temp->right)//if(temp->right==NULL)
        {
            temp->right=newNode(key);
            break;
        }
        else
        {
            q.push(temp->right);
        }
        
    }
}
int main() 
{   

    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->left->left = newNode(3); 
    root->right = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 

    cout << "Inorder traversal before insertion:"; 
    inorder(root); 

    int key = 7; 
    insert(root, key); 

    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 

    return 0; 
} 