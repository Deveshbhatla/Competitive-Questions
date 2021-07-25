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

bool isLoop(Node *head) // Modify's the Linked List
{
    Node *temp = new Node(0);
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->next == NULL)
            return false;
        if (curr->next == temp)
            return true;

        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}
bool isLoopHashing(Node *head) //No Modification is required O(n) time and space
{
    unordered_set<Node *> s;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return false;
}
bool isLoopFlyodCycleDetection(Node *head) //O(n) time, O(1) Space
{
    Node *slow_p = head, *fast_p = head;

    while (fast_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    if (isLoopFlyodCycleDetection(head))
        cout << "Loop found";
    else
        cout << "No Loop found";
    return 0;
}
