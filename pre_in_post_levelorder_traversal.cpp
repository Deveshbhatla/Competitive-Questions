//preorder,inorder,postorder and level order traversal of a binary tree
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int key;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};

void printPreorder(struct Node *node)
{
    if(node==NULL)
    return;
    cout<<node->key<<" ";
    printPreorder(node->left);
    printPreorder(node->right);

}

void printinOrder(struct Node *node)
{
    if(node==NULL)
    return;
    printinOrder(node->left);
    cout<<node->key<<" ";
    printinOrder(node->right);
}

void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->key << " ";
}

void printLevelorder(struct Node *root_node)
{
    if(root_node==NULL)
    return;
    queue<Node*> q;
    q.push(root_node);

    while(q.empty()==false)
    {
        Node *node=q.front();
        cout<<node->key<<" ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL) 
            q.push(node->left); 

        /* Enqueue right child */
        if (node->right != NULL) 
            q.push(node->right); 

    }   

}

int main()
{
    Node *root;
    root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<"PreOrder : ";printPreorder(root);
    cout<<"\nInorder: "; printinOrder(root);
    cout<<"\nPost order: "; printPostorder(root);
    cout<<"\nLevel Order: "; printLevelorder(root);
    return 0;
}
