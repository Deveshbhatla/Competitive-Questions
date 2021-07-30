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

void deleteNode(Node *ptr)
{
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete (temp);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    Node *ptr = new Node(3);
    head->next->next = ptr;
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printlist(head);
    deleteNode(ptr);
    cout << "deleting 3rd pointer" << endl;
    printlist(head);
    return 0;
}
