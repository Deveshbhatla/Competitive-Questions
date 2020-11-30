#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *prev,*next;
    int key;
    Node(int x)
    {
        key =x;
        prev=NULL;
        next=NULL;
    }
};
Node *DeleteHead(Node *head)
{       
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        {
           delete head;
            return head;
        }
    Node *cur=head;
    cur=cur->next;
    delete head;
    return cur;

}
Node *DeleteEnd(Node *head)
{
   
    if(head==NULL)return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    Node *prev,*cur=head;
    while(cur->next!=NULL)
        cur=cur->next;

    cur->prev->next=NULL;
    delete cur;
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

    head=DeleteHead(head);
    head= DeleteEnd(head);
    Node *cur=head;
    while (cur!=NULL)
    {
        cout<<cur->key;
        cur=cur->next;
    }
    
    return 0;
}