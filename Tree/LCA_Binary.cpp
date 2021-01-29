#include<bits/stdc++.h>
using namespace std;
struct Node 
{
    int key;
    struct Node *left, *right;
};

Node* newNode(int k)
{
    Node* temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find the path from root node to given root of the tree, Stores the path in a vector path[], returns true if path exists
// otherwise false
bool findPath(Node* root, vector<int>& path, int k)
{
    
    if (root == NULL)
        return false;

    // Store this node in path vector. The node will be removed if not in path from root to k
    path.push_back(root->key);

    // See if the k is same as root's key
    if (root->key == k)
        return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) || 
        (root->right && findPath(root->right, path, k)))
        return true;

    // If not present in subtree rooted with root, remove root from path[] and return false
    path.pop_back();
    return false;
}

int findLCA(Node* root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;

    int i;

    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;

    return path1[i - 1];
}

int main()
{
    
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "LCA(4,5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4,6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3,4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2,4) = " << findLCA(root, 2, 4);
    cout << "\nLCA(1,2) = " << findLCA(root, 1, 2);

    return 0;
}
