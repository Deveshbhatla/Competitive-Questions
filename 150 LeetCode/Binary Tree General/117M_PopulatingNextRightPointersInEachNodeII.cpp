// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.


// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/**
 * using Level Order Traversal and connecting adjacent Nodes
 * BFS
 * Time Complexity->O(n)
 * Space complexity->O(n)
 */
Node *connect(Node *root)
{
    if (!root)
        return nullptr;

    vector<vector<Node *>> level;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<Node *> temp;

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            temp.push_back(node);
        }
        temp.push_back(NULL);
        level.push_back(temp);
    }

    for (int i = 0; i < level.size(); i++)
        for (int j = 0; j < level[i].size() - 1; j++)
            level[i][j]->next = level[i][j + 1];

    return root;
}

// helper function to print the tree
void print2DUtil(Node *root, int indent)
{
    if (root == NULL)
        return;

    // Increase distance between levels
    indent += COUNT;

    // Process right child first
    print2DUtil(root->right, indent);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < indent; i++)
        cout << " ";
    cout << root->val << "\n";

    // Process left child
    print2DUtil(root->left, indent);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    // Second level
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(7);

    print2DUtil(connect(root), 0);

    return 0;
}