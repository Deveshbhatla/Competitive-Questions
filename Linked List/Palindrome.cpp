#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char x)
    {
        data = x;
        next = NULL;
    }
};
//Using stack O(n) space and O(n) time
bool isPalindrome(Node *head)
{
    stack<char> st;
    //adding all the data into the stack
    for (Node *cur = head; cur != NULL; cur = cur->next)
    {
        st.push(cur->data);
    }

    for (Node *cur = head; cur != NULL; cur = cur->next)
    {
        if (st.top() != cur->data)
            return false;
        st.pop();
    }
    return true;
}

Node *reverseList(Node *head)
{
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

//Find the middle node and reverse the list after that node
bool isPalindromeEfficient(Node *head)
{
    if (head == NULL)
        return true;

    Node *slow = head, *fast = head;

    //finding the middle node
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *rev = reverseList(slow->next);

    Node *curr = head;
    while (rev != NULL)
    {
        if (rev->data != curr->data)
            return false;
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}

int main()
{
    Node *head = new Node('e');
    head->next = new Node('y');
    head->next->next = new Node('e');

    cout << isPalindrome(head);
    cout << isPalindromeEfficient(head);

    return 0;
}