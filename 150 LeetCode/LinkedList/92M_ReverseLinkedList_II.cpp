// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.
// https://leetcode.com/problems/reverse-linked-list-ii/

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
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (!head || left == right)
        return head;

    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *prev = dummyNode;

    //Traverse prev list until the node just before left-th node is reached
    for (int i = 0; i < left - 1; ++i)
    {
        prev = prev->next;
    }

    //use current to keep track of the starting point in the sublist prev
    ListNode *current = prev->next;

    //reverse the sublist
    for (int i = 0; i < right - left; i++)
    {
        ListNode *next_node = current->next;
        current->next = next_node->next;
        next_node->next = prev->next;
        prev->next = next_node;
    }

    ListNode *result=dummyNode->next;

    //To avoid memory leak, we delete dummy
    delete dummyNode;
    return result;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2, right = 4;

    cout << "Original list :" << endl;
    displayList(head);
    cout << endl;

    cout << "After reversing the list between two mumbers:" << endl;
    ListNode *reversedList = reverseBetween(head, left, right);
    displayList(reversedList);

    return 0;
}