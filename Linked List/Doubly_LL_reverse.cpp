#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *prev,*next;
    int key;
    Node(int x)
    {
        key=x;
        prev=NULL;
        next=NULL;
    }
};
Node *reverse(Node *head)// O(n)
{
    if(head==NULL||head->next==NULL)
    return head;
    Node *temp=NULL,*cur=head, *NewHead;
    while(cur!=NULL)
    {
        //swapping
        temp=cur->prev;
        cur->prev=cur->next;
        cur->next=temp;

        NewHead=cur;
        cur=cur->prev;
    }    
    return NewHead;
}

int main()
{
    Node *head=new Node(1);
    Node *node1=new Node(2);
    Node *node2 =new Node(3);
    head->next=node1;
    node1->prev=head;
    node1->next=node2;
    node2->prev=node1;

    head=reverse(head);

    Node *cur=head;
    while (cur!=NULL)
    {
        cout<<cur->key;
        cur=cur->next;
    }
    
    return 0;

}