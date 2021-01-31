/*Given a Binary Search Tree (BST), modify it so that all greater values in the given BST are added to every node.
In this function problem, the task is to complete the function modify which takes one argument: Address of the root of the BST. The function should contain the logic to modify the BST so that in the modified BST, every node has a value equal to the sum of its value in the original BST and  values of all the elements larger than it in the original BST.

The BST node structure has 3 fields, a data part which stores the data, a left pointer which points to the left element of the BST and a right pointer which points to the right node of the BST.

There are multiple test cases. For each test case, this function will be called individually.*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
void inorderrrrr(Node *root)
{
    if(root!=NULL)
    {
    inorderrrrr(root->left);
    cout<<root->data<< " ";
    inorderrrrr(root->right);
    }
}
void modify(Node **root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        modify(&root);
        inorderrrrr(root);
        cout<<endl;
    }
}


//User function Template for C++

/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*  modifies the root of the bst */

/*Example:
Input:
1
7
50 30 20 40 70 60 80

Output:
350 330 300 260 210 150 80*/
//My code starts from here
void modifyBST(Node* root, int* sum) 
{ 
    if (root == NULL) 
        return; 
    modifyBST(root->right, sum); 
    //*sum has sum of nodes in right subtree, add root->data to sum and update root->data 
    *sum = *sum + root->data; 
    root->data = *sum; 
  
    modifyBST(root->left, sum); 
} 
void modify(Node **root)
{
    int sum = 0; 
    modifyBST(*root, &sum);
}