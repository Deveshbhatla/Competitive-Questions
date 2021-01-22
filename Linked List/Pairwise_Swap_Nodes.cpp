//Given a linked list of N positive integers. You need to swap elements pairwise. Your task is to complete the function pairwise_swap().
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

//My Code Starts From here
struct Node* pairwise_swap(struct Node* head)
{
    Node*temp=head; 
    while (temp!=NULL&&temp->next!=NULL)
    { 
        swap(temp->data,temp->next->data); 
        temp=temp->next->next; 
    } 
    return head;
}

void printList(struct Node* node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", (node)->data); 
        node = (node)->next; 
    } 
}
int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n, l;
        cin>>n;
         struct Node* head = NULL;
      struct Node* tail = NULL;
        
        for(int i = 1; i <= n; i++)
        {
            cin>>l;
            append(&head,&tail, l);
        }
        head =pairwise_swap(head);
        printList(head);
        cout << endl;
    }
}  