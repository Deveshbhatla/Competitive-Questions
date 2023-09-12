// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node *next;
    int current_minimum;
};

class MinStack {
    Node *head;

public:
    MinStack() {
        head=NULL;
    }
    
    void push(int val) {
        Node *temp=new Node();
        temp->value=val;
        temp->next=head;
        if(head)
            temp->current_minimum=min(val,head->current_minimum);
        else
            temp->current_minimum=val;

        head=temp;
    }
    
    void pop() {
        head=head->next;
    }
    
    int top() {
        if(head!=NULL)
            return head->value;
        else
            return 0;
    }
    
    int getMin() {
        if(head!=NULL)
            return head->current_minimum;
        else
            return 0;
    }
};


int main()
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);

    cout<<"Minimum now: "<<obj->getMin()<<endl;
    obj->pop();
    cout<<"top: "<< obj->top()<<endl;
    cout<<"Minimum now: "<<obj->getMin()<<endl;
    
    return 0;
}