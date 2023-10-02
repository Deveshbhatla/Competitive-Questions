// Given the head of a linked list, rotate the list to the right by k places.

// https://leetcode.com/problems/rotate-list/

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
ListNode *RotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    //Calculating the length of the list    
    ListNode *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }


    //If k is more than the length of the list
    k = k % length;
    if (k == 0)
        return head;

    int count = 0;
    ListNode *end = head;//End of the list till the first part of the list after k
    ListNode *solution = head->next;
    ListNode *last = head;// end of the list before k

    //End of the list before k
    while (count < k)
    {
        end = end->next;
        count++;
    }

    //traversing the remaining nodes
    while (end->next != NULL)
    {
        end = end->next;
        solution = solution->next;
        last = last->next;
    }

    end->next = head;
    last->next = NULL;
    return solution;
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

    int k = 2;

    cout << "Original list :" << endl;
    displayList(head);
    cout << endl;

    cout << "After Rotating k times:" << endl;
    ListNode *rotateRightList = RotateRight(head, k);
    displayList(rotateRightList);

    return 0;
}