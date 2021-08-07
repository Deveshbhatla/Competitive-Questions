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

Node *sortedMerge(Node *a, Node *b)
{
    //corner cases
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;


//Head would be updated only once(to return it), tail would move forward
//if data of 1st is less than second then initialize head and tail with that pointer and then move the a or b forward
    Node *head = NULL, *tail = NULL;
    if (a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }


    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        { 
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

//if any of the linkedlist become empty, we come out of the loop and then 
//append the linked list with remaining elements at the end of the tail
    if (a == NULL)
    {
        tail->next = b;
    }
    else
    {
        tail->next = a;
    }

    return head;
}

int main()
{
    Node *a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    
    Node *b = new Node(5);
    b->next = new Node(35);

    printlist(sortedMerge(a, b));
    
    return 0;
}
