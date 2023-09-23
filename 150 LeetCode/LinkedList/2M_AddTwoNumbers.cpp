//You are given two non-empty linked lists representing two non-negative integers. 
//The digits are stored in reverse order, and each of their nodes contains a single digit. 
//Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//https://leetcode.com/problems/add-two-numbers/

#include <iostream>
using namespace std;

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

    ListNode *addTwoNumbers(ListNode *, ListNode *);
};

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

ListNode *Linkedlist::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;
    bool carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int digit1 = (l1 != nullptr) ? l1->val : 0;
        int digit2 = (l2 != nullptr) ? l2->val : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);
        tail->next = newNode;
        tail = tail->next;

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    ListNode *result = dummyHead->next;

    //To avoid memory leak, we are deleting dummyhead
    delete dummyHead;

    return result;
}

int main()
{
    Linkedlist l1;
    Linkedlist l2;
    Linkedlist result;
    ListNode *res;

    l1.insertNode(2);
    l1.insertNode(4);
    l1.insertNode(3);

    l2.insertNode(5);
    l2.insertNode(6);
    l2.insertNode(4);

    l1.printList();
    cout << endl;
    l2.printList();
    cout << endl;

    res = result.addTwoNumbers(l1.head, l2.head);
    while (res != NULL)
    {
        cout << res->val;
        res = res->next;
    }

    return 0;
}