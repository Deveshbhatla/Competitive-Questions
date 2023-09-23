//You are given the heads of two sorted linked lists list1 and list2.
//Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
//Return the head of the merged linked list.

//https://leetcode.com/problems/merge-two-sorted-lists/

#include <iostream>
using namespace std;

//NODE Class
class ListNode
{
public:
    int val;
    ListNode *next;

    // Default constructor
    ListNode()
    {
        val = 0;
        next = NULL;
    }

    // Parameterised Constructor
    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

//LinkedList Class for creating multiple linked lists
class Linkedlist
{
public:
    ListNode *head;
    // Default constructor
    Linkedlist() { head = NULL; }

    // Function to insert a node at the end of the linked list.
    void insertNode(int);

    // Function to print the linked list.
    void printList();

    ListNode *mergeTwoLists(ListNode *, ListNode *);
};

//Helper INSERT and PRINT functions
void Linkedlist::insertNode(int data)
{
    ListNode *newNode = new ListNode(data);

    // Assign to head
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Traverse till end of list
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}

void Linkedlist::printList()
{
    ListNode *temp = head;
    ListNode *resultList = temp;

    // Check for empty list.
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL)
    {
        cout << temp->val;
        temp = temp->next;
    }
}


//merge two sorted lists in sorted manner
ListNode *Linkedlist::mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *dummy, *temp;
        dummy = new ListNode();
        temp = dummy;
        
        //when both list1 and list2 aren't empty
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;   
            }
            temp = temp->next;
        }
        
        // we reached at the end of one of the list
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        
        temp=dummy->next;

        //To avoid memory leak, we delete dummy list
        delete dummy;
        return temp;
    }
int main()
{
    Linkedlist l1;
    Linkedlist l2;
    Linkedlist result;
    ListNode *res;

    l1.insertNode(1);
    l1.insertNode(2);
    l1.insertNode(4);

    l2.insertNode(1);
    l2.insertNode(3);
    l2.insertNode(4);

    l1.printList();
    cout << endl;
    l2.printList();
    cout << endl;

    res = result.mergeTwoLists(l1.head, l2.head);
    while (res != NULL)
    {
        cout << res->val;
        res = res->next;
    }

    return 0;
}