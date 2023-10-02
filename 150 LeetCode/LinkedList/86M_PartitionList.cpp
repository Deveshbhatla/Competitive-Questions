// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.

// https://leetcode.com/problems/partition-list/

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
ListNode *partition(ListNode *head, int x)
{
    ListNode *Prev = new ListNode(0);
    ListNode *Next = new ListNode(0);
    ListNode *prev_curr = Prev;
    ListNode *next_curr = Next;

    while (head)
    {
        //If Linkedlist value is greater than x, then next_curr's swaps with head
        if (head->val >= x)
        {
            next_curr->next = head;
            next_curr = head;
        }
        else
        {
            prev_curr->next = head;
            prev_curr = head;
        }
        head = head->next;
    }

    next_curr->next = NULL;
    prev_curr->next = Next->next;

    return Prev->next;//Start of the list

}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    cout << "Original list :" << endl;
    displayList(head);
    cout << endl;

    cout << "After Partiioning times:" << endl;
    ListNode *partiionList = partition(head, x);
    displayList(partiionList);

    return 0;
}