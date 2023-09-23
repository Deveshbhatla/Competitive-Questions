//Given head, the head of a linked list, determine if the linked list has a cycle in it.

//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
//Note that pos is not passed as a parameter.

//Return true if there is a cycle in the linked list. Otherwise, return false.

//https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* head = NULL;

bool hasCycle(ListNode *head)
{
        ListNode *fastPointer=head;
        ListNode *slowPointer=head;

       //this loop will increment the fastpointer 2 times, and slow pointer once.
       //If both the pointers meet at any point, then the list contains a cycle.
        while(fastPointer!=NULL &&fastPointer->next!=NULL)
        {
            fastPointer=fastPointer->next->next;
            slowPointer=slowPointer->next;

            if(fastPointer==slowPointer)
                return true;
        }
        return false;
}

void insertNode(int data)
{
    ListNode* newNode = new ListNode(data);
  
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    // Traverse till end of list
    ListNode* temp = head;
    while (temp->next != NULL) {
          temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;
}

void displayList() 
{
    ListNode *temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main()
{
    insertNode(1);
    insertNode(2);
    insertNode(3);
    displayList();
    cout<<endl;
    cout<<hasCycle(head);

    return 0;

}