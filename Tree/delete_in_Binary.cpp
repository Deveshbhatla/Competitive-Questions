#include<bits/stdc++.h>
using namespace std;

struct Node 
{ 
    int key; 
    struct Node* left, *right; 
}; 

struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 

void inorder(struct Node* temp) 
{ 
    if (!temp) 
        return; 
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 

void delete_deepest(Node *root,Node*deepest_node)
{
    queue<struct Node*> q; 
    q.push(root); 

    // Doing level order traversal until last node 
    struct Node* temp; 
    while(!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 

        if (temp->right) 
        { 
            if (temp->right == deepest_node) 
            { 
                temp->right = NULL; 
                delete(deepest_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 

        if (temp->left) 
        { 
            if (temp->left == deepest_node) 
            { 
                temp->left=NULL; 
                delete(deepest_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
}

void deletion(struct Node* root, int key) 
{ 
    queue<struct Node*> q; 
    q.push(root); 

    struct Node *temp; 
    struct Node *key_node = NULL; 

    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 

        if (temp->key == key) 
            key_node = temp; 

        if (temp->left) 
            q.push(temp->left); 

        if (temp->right) 
            q.push(temp->right); 
    } 

    int x = temp->key; 
    delete_deepest(root, temp); 
    key_node->key = x; 
} 
int main() 
{   
    // Create the following Binary Tree
    //            1
    //         /      \
    //        2        5
    //       /  \     / \
    //      3    4   6    7  
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(4); 
    root->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 

    cout << "Inorder traversal before deletion : "; 
    inorder(root); 

    int key = 2; 
    deletion(root, key); 

    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 

    return 0; 
} 