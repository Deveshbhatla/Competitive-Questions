#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int key;
    Node* next;
    Node(int x)
    {
        key=x;
        next=NULL;
    }
};


Node *reverse(Node *head)
{
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL)
    {
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node *RecursiveReverse(Node *head)
{
    if(head==NULL||head->next==NULL)return head;
    Node *rest_head=RecursiveReverse(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

int main() 
{ 
	Node *head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
    
	//head=reverse(head);
        // while(head!=NULL)
        // {
        // cout<<head->key;
        // head=head->next;
        // }


        head=RecursiveReverse(head);
        while(head!=NULL)
        {
        cout<<head->key;
        head=head->next;
        }        return 0;

} 