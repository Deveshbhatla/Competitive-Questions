#include<bits/stdc++.h>
using namespace std;

//Method 1 making push operation costly
class Stack
{
    queue<int>q1,q2;
    int current_size;//to maintain current number of elements
    public:
    Stack()
    {
        current_size=0;
    }
    void push(int x)
    {
        current_size++;
        q2.push(x);
        while(!q1.empty())//push elements into q2 if q1 is not empty
        {
            q2.push(q1.front());
            q1.pop();
        }
        //swapping the queues
        queue<int> q=q1;
        q1=q2;
        q2=q;
    }
    void pop()
    {
        if(q1.empty())
            return;
        q1.pop();
        current_size--;
    }
    int top()
    {
        if(q1.empty())
            return -1;
        return q1.front();
    }
    int size()
    {
        return current_size;
    }
};
// Making pop operation costly
class Stack1
{
        queue<int> q1, q2;
    int curr_size;

    public:
    Stack1()
    {
        curr_size = 0;
    }

    void pop()
    {
        if (q1.empty())
            return;

        // Leave one element in q1 and 
        // push others in q2.
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the only left element 
        // from q1
        q1.pop();
        curr_size--;

        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void push(int x)
    {
        q1.push(x);
        curr_size++;
    }

    int top()
    {
        if (q1.empty())
            return -1;

        while( q1.size() != 1 )
        {
           q2.push(q1.front());
           q1.pop();
        } 
        
        // last pushed element
        int temp = q1.front();
        
        // to empty the auxiliary queue after
        // last operation
        q1.pop();
     
        // push last element to q2
        q2.push(temp);

        // swap the two queues names
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }

    int size()
    {
        return curr_size;
    }


};
int main()
{
    Stack s;
     s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size() 
        << endl;
    return 0;
}