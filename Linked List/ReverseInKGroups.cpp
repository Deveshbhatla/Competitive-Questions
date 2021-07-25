#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next;
    int data;
    Node(int x) // to initialize the values from main function
    {
        data = x;
        next = NULL;
    }
};
//Recursive solution O(n)
Node *recursiveReverseInKGroups(Node *head, int k)
{
    Node *cur = head, *prev = NULL, *next = NULL;
    int count = 0;
    while (cur != NULL & count < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;

        count++;
    }

    if (next != NULL) //if the end of Linked List is not reached then process remaining nodes
    {
        Node *rest_head = recursiveReverseInKGroups(next, k);
        head->next = rest_head;
    }
    return prev;
}
Node *reverseIterativeInGroupsOfK(Node *head, int k)
{
    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;//Only for first group

    while (curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

   /* head = recursiveReverseInKGroups(head, 3); //3216547
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }*/

    head = reverseIterativeInGroupsOfK(head, 3); //3216547
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
    return 0;
}