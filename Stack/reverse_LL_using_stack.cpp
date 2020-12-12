#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next;
    int data;
    Node(int x)
    {
        data=x;
    }
};
void reverseLL(Node *head) //Time Complexity : O(n) Space : O(n)
{
    
    stack<int> s;
    Node *cur=head;
    while(cur!=NULL)
       {
            s.push(cur->data);
            cur=cur->next;
       } 
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }


}
int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);

    reverseLL(head);

}
