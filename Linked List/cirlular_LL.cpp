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
Node *InsertAtBeg(Node *head, int x)
{   Node *temp=new Node(x);
    if(head==NULL)
        temp->next=temp;
    else
    {
        Node *cur=head;
        while(cur->next!=head)
            cur=cur->next;

        cur->next=temp;
        temp->next=head;
    }
    return temp;
}
int main()
{
    Node * head= new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=head;
    if(head==NULL)
    return 0;
            head=InsertAtBeg(head,8);

       Node *p=head;
        do
        {
        cout<<p->key;
        p=p->next;
        } while (p!=head);
    
    // cout<<head->key;
    // for(Node *ptr=head->next;ptr!=head;ptr=ptr->next)
    // {
    //     cout<<ptr->key;
    // }
    return 0;
}