// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes,
// where each new node has its value set to the value of its corresponding original node.
// Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state.
// None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <iostream>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void displayList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->val << " " << curr->random->val <<" -> ";
        curr = curr->next;
    }
}

// Copy Random list
Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;

    unordered_map<Node *, Node *> oldToNew;
    Node *curr = head;

    // Traversing the original list and for each list create a corresponding new node and store it in a hashmap
    while (curr)
    {
        oldToNew[curr] = new Node(curr->val);
        curr = curr->next;
    }

    // reset curr to point to head
    curr = head;

    // traverse each list and then assign the corresponding new node next and random pointers based on the hashmap
    while (curr)
    {
        oldToNew[curr]->next = oldToNew[curr->next];
        oldToNew[curr]->random = oldToNew[curr->random];
        curr = curr->next;
    }

    Node *res = oldToNew[head];

    return oldToNew[head];
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);


    head->random = head->next->next->next->next;
    head->next->random = head;
    head->next->next->random =head->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;


    cout << "Original list :" << endl;
    displayList(head);
    cout<<endl;
    cout << "After performing deep copy of the list:" << endl;
    Node *deepCopyList = copyRandomList(head);
    displayList(deepCopyList);

    return 0;
}