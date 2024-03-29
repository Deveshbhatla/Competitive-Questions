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

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *segregate(Node *head)
{
    Node *evenStart = NULL, *evenEnd = NULL, *oddStart = NULL, *oddEnd = NULL;

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        int x = curr->data;
        if (x % 2 == 0)
        {
            if (evenStart == NULL)// For 1st even node
            {
                evenStart = curr;
                evenEnd = evenStart;
            }
            else
            {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        }
        else
        {
            if (oddStart == NULL)
            {
                oddStart = curr;
                oddEnd = oddStart;
            }
            else
            {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
    }
    if (oddStart == NULL || evenStart == NULL)
        return head;

    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    
    return evenStart;
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
    printlist(head);
    head = segregate(head);
    printlist(head);
    return 0;
}
