// Given a circular doubly linked list, the task is to update the data of a node with the sum of data of all the nodes except itself.
//The tail of a circular doubly linked list is connected to head via its next pointer, and the previous pointer of head is connected to the tail.
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}

Node *addNode(Node *head, int data)
{
    if(head==NULL)
    head=newNode(data);
    else
    {
        Node * temp=head;
        Node * prev=head;
        while(temp->next)
            {
                prev=temp;
                temp=temp->next;
                
            }
        temp->next=newNode(data);
        prev=temp;
        temp=temp->next;
        temp->prev=prev;
    }
    
    return head;
}

void displayList(Node *head)
{
    //Head to Tail
    Node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
    
    //Tail to Head
    
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<temp->data;
    
}

// My code Starts From here
void sumUpdate(Node *head)
{
    int sum=0;
    Node *current=head;
    sum+=head->prev->data;

    while(current->next!=head)
    {
        sum+=current->data;
        current =current->next;
    }

    Node *temp=head;
    while(temp->next!=head)
    {
        temp->data=sum-temp->data;
        temp=temp->next;
    }
    temp->data=sum-(temp->data);
    
}

void makeCircular(Node * head)
{
    Node * temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
    }
    
    temp->next=head;
    head->prev=temp;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        head=addNode(head,x);
	    }
	    
	    
	    makeCircular(head);
	    
	    sumUpdate(head);
	    displayList(head);
 
	    cout<<endl;
	}
	return 0;
}  