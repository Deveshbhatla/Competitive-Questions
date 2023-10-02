// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// Return the linked list sorted as well.

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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

// Delete Duplicates
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *previous = dummy, *current = head;

    while (current)
    {
        ListNode *next_node = current->next;
        while (next_node && current->val == next_node->val)//if duplicate found
        {
            ListNode *temp = next_node->next;
            delete next_node;
            next_node = temp;
        }

        if (current->next == next_node)
        {
            previous = current;
        }
        else //also deleting the current node according to the question requirements
        {
            previous->next = next_node;
            delete current;
        }
        current = next_node;
    }

    return dummy->next;
    
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original list :" << endl;
    displayList(head);
    cout << endl;

    cout << "After removing duplicates:" << endl;
    ListNode *deleteDuplicatesList = deleteDuplicates(head);
    displayList(deleteDuplicatesList);

    return 0;
}