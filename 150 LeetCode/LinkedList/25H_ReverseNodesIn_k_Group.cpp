// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// https://leetcode.com/problems/reverse-nodes-in-k-group/

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

// Reverse in k groups
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *before = dummy;
    ListNode *after = head;
    ListNode *curr = nullptr;
    ListNode *prev = nullptr;
    ListNode *nxt = nullptr;
    while (true)
    {
        ListNode *cursor = after;
        for (int i = 0; i < k; i++)
        {
            if (cursor == nullptr)
                return dummy->next;
            cursor = cursor->next;
        }
        curr = after;
        prev = before;
        for (int i = 0; i < k; i++)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        after->next = curr;
        before->next = prev;
        before = after;
        after = curr;
    }
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);


    cout << "Original list :" << endl;
    displayList(head);
    cout << endl;

    cout << "After reversing the list in groups of 2:" << endl;
    ListNode *reversedList = reverseKGroup(head, 2);
    displayList(reversedList);

    return 0;
}