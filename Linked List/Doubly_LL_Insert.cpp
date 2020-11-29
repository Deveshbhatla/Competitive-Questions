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
Node *InsertAtBegin(Node *head,int x)
{
    Node *temp=new Node(x);
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}
Node *InsertAtEnd(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return head;
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

    head=InsertAtBegin(head,4);
    head=InsertAtEnd(head,5);
    
    Node *cur=head;
    while (cur!=NULL)
    {
        cout<<cur->key;
        cur=cur->next;
    }
    
    return 0;

}