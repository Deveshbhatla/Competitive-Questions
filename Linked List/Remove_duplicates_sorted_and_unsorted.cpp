#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
struct Node
{
    Node *next;
    int key;
    Node(int k)
    {
        key=k;
        next=NULL;
    }
};
void RemoveDuplicatesSorted(Node *head)
{
    Node *cur=head;
    while(cur!=NULL && cur->next!=NULL)
    {
        if(cur->key==cur->next->key)
        {
            Node * temp=cur->next;
            cur->next=cur->next->next;
            delete temp;    
        }
        else
        {
            cur=cur->next;
        }
        
    }
}
void RemoveDuplicatesUnsorted(Node * head) //Using Unordered Set, O(N) time
{
    unordered_set<int> uset;
    Node *cur = head; 
    Node *Prev= NULL;
    while(cur!=NULL)
    {
        if(uset.find(cur->key)!=uset.end())// head is present        // If current value is seen before 
        {
            Prev->next=cur->next;
            delete cur;
        }
        else
        {
            uset.insert(cur->key);
            Prev=cur;
        }
        cur=cur->next;
    }

}

void DeleteUnsortedNoBuffer(Node * head) // two pointer O(1) Space O(N2) time
{
    Node *cur=head;
    while(cur!=NULL)
    {
        Node *runner=cur;
        while(runner->next!=NULL)
        {
            if(runner->next->key==cur->key)
            {
                runner->next=runner->next->next;
            }
            else
            {
                runner=runner->next;
            }
            
        }
        cur=cur->next;
    }
}

int main()
{
    Node *head =new Node(2);
    head->next=new Node(8);
    head->next->next=new Node(5);
    head->next->next->next=new Node(1);
     head->next->next->next->next=new Node(2);

    RemoveDuplicatesSorted(head);
    RemoveDuplicatesUnsorted(head);
     DeleteUnsortedNoBuffer(head);

    while(head!=NULL)
    {
        cout<<head->key;
        head=head->next;
    }
    return 0;

}
