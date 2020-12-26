#include<bits/stdc++.h>
using namespace std;
void Reverse_K(queue<int>& q,int k)
{
    if(q.empty()||k>q.size())
        return ;
    if(k<=0)
        return;

    stack<int> s;

    for(int i=0;i<k;i++)// pushing the first k elements of the queue into the stack
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) //pushing the elements from stack top to queue rear
    {
        q.push(s.top());
        s.pop();
    }

    for(int i=0;i<q.size()-k;i++)// moving the remaining elements from the front of the queue to rear to maintain the original queue pattern
    { 
        q.push(q.front());
        q.pop();
    }


}
void printqueue(queue<int>& q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main()
{
    queue<int> Q;
    int k;
    cin>>k;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);
    Q.push(7);
    Q.push(8);
    Q.push(9);
    Q.push(10);
    Q.push(11);
    Q.push(12);
    Reverse_K(Q,k);
    printqueue(Q);
    return 0;

}