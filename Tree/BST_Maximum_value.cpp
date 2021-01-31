
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node* insert(Node* node, int data) 
{
    
    if(node == NULL) return(new Node(data)); 
    else
    {
        if (data <= node->data)node->left = insert(node->left, data);
        else node->right = insert(node->right, data);
        return node; 
    }
}

int maxValue(Node* root);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, tmp;
        cin>>n>>tmp;
        Node* root = NULL;
        root = insert(root, tmp);
        n--;
        while(n--){
            cin>>tmp;
            insert(root, tmp);
        }
        cout<<maxValue(root)<<endl;
    }
    return 0;
}



//User function Template for C++


/*
Structure of the node of the binary search tree is as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// My code starts from here
int maxValue(Node* root)
{
    if (root == NULL) 
        return INT_MIN; 

    int result = root->data; 

    int left_result = maxValue(root->left); 
    int right_result = maxValue(root->right); 

    if (left_result > result) 
        result = left_result; 
    if (right_result > result) 
        result = right_result; 
    return result; 
}
