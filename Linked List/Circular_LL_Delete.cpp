#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next;
    int key;
    Node(int x)
    {
        key=x;
        next=NULL;
    }
};
Node *DeleteFromBeg(Node *head)
{
 if(head==NULL)
    return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    Node *cur=head;
    while(cur->next!=head)
        cur=cur->next;
    cur->next=head->next;
    delete head;
    return (cur->next);
}
Node *DeleteFromBegEfficient(Node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    head->key=head->next->key;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}
Node *DeleteFromEnd(Node* head)
{
    if(head==NULL)return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    Node *prev,*cur=head;
    while(cur->next!=head)
    { 
        prev=cur;
        cur=cur->next;
    
    }
    prev->next=head;
    delete cur;
    return head;
}

Node *DeleteKth(Node *head,int k)
{
    if(head==NULL)
        return head;
    if(k==1)
    return DeleteFromBeg(head);
    
    Node *cur=head;
   for(int i=0;i<k-2;i++)
        cur=cur->next;
    Node *temp=cur->next;
    cur->next=cur->next->next;
    delete temp;
    return head;
}
int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=head;
    
    if(head==NULL)
        return 0; 
        //head=DeleteFromBeg(head);
        //head= DeleteFromBegEfficient(head);
        //head=DeleteFromEnd(head);
        head=DeleteKth(head,1);
       Node *cur=head;
        do
        {
            cout<<cur->key;
            cur=cur->next;
        }
        while (cur!=head);

        // cout<<head->key;
    // for(Node *ptr=head->next;ptr!=head;ptr=ptr->next)
    // {
    //     cout<<ptr->key;
    // }
    return 0;
}