// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
using namespace std;

// Definition for a Node.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void displayList(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
}

// Reverse bewteen 2 positions
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;// pointing dummy's next to head
    ListNode *fast = dummy, *slow = dummy;

    //Scroll to the nth value from the begining;
    for (int i = 0; i < n; i++)
        fast = fast->next;

    //After this loop, the slow will point to the node you want to delete
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    //creating temp to delete the node
    ListNode *temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return dummy->next;// As dummy->next points towards head
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    cout << "Original list :" << endl;
    displayList(head);
    cout << endl;

    cout << "After Removing the Nth node from the end of the list:" << endl;
    ListNode *removeNthList = removeNthFromEnd(head, n);
    displayList(removeNthList);

    return 0;
}