#include<bits/stdc++.h>
using namespace std;
//USING ARRAY
#define MAX 1000

class Stack
{
    int top;
    public:
    int a[MAX];    //Maximum size of Stack

    Stack()  { top = -1; }
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX-1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout<<x <<" pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}


//USING LINKED LIST
struct node
{
  int data;
  node *next;
  node(int x){
        data=x;
        next=NULL;
    }
};

class Stack_LL
{
      node *top;
public :
      Stack_LL()
      { top=NULL;}
       void push(int x);
       void pop();
       void display();
      ~Stack_LL();
};

void Stack_LL::push(int x)
{
        node *temp=new node(x);
      temp->next=top;
      top=temp;
}

void Stack_LL::pop()
{
      if(top!=NULL)
      {
            node *temp=top;
            top=top->next;
            cout<<temp->data<<" deleted"<<'\n';
            delete temp;
      }
      else
            cout<<"Stack empty";
}

void Stack_LL::display()
{
      node *temp=top;
      while(temp!=NULL)
      {
        cout<<temp->data<<" "<<'\n';
        temp=temp->next;
      }
}

Stack_LL::~Stack_LL()
{
      while(top!=NULL)
      {
            node *temp=top;
            top=top->next;
            delete temp;
      }
}




int main()
{
// class Stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);

//     cout<<s.pop() << " Popped from stack\n";



     Stack_LL st;
st.push(1);
    st.push(2);
    st.push(3);
    cout<<"Before deleting"<<'\n';
    st.display();

   st.pop();
//     cout<<st.size()<<endl;
//     cout<<st.peek()<<endl;
//     cout<<st.isEmpty()<<endl;
cout<<"After deleting"<<'\n';
st.display();

    return 0;
}
