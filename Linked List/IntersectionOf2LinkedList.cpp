#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int getIntersection(Node *head1, Node *head2)//using hashing time:O(m+n)
{
    unordered_set<Node *> s;

    Node *curr = head1;
    while (curr != NULL)
    {
        s.insert(curr);
        curr = curr->next;
    }
    
    curr = head2;
    while (curr != NULL)
    {
        if (s.find(curr) != s.end())
            return curr->data;
        curr = curr->next;
    }
    return -1;
}

int main()
{

    Node *newNode;

    Node *head1 = new Node(10);
    Node *head2 = new Node(1);

    newNode = new Node(2);
    head2->next = newNode;

    newNode = new Node(3);
    head2->next->next = newNode;

    newNode = new Node(4);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(5);
    head1->next->next = newNode;
    head1->next->next->next = NULL;

    cout << getIntersection(head1, head2);
    return 0;
}