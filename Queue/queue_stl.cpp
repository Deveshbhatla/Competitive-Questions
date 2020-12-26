/*The functions supported by std::queue are :
empty() – Returns whether the queue is empty.
size() – Returns the size of the queue.
swap(): Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
emplace(): Insert a new element into the queue container, the new element is added to the end of the queue.
front() and back(): front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
push(g) and pop(): The push() function adds the element ‘g’ at the end of the queue. The pop() function deletes the first element of the queue.
*/

#include <iostream> 
#include <queue> 

using namespace std; 
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.emplace(6);

    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
    return 0;
}
