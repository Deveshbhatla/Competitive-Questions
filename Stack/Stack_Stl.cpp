/*Some Basic functions of Stack class in C++:
empty() – Returns whether the stack is empty.
size() – Returns the size of the stack.
top() – Returns a reference to the topmost element of the stack.
push(x) – Adds the element 'x' at the top of the stack.
pop() – Deletes the topmost element of the stack.

//in c++ 11 only
s1.swap(s2)- swaps the content of two stacks s1 and s2 of the same type, sizes can be different
emplace(x)- Adds a new element at the top of the stack, above its current top element. This new element is constructed in place passing args as the arguments for its constructor.
All of the above functions work in O(1) time complexity.*/

#include<bits/stdc++.h>
using namespace std;

void display(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
} 
  
int main () 
{ 
    stack <int> s,s1; 
    s.push(1); s1.push(6);
    s.push(2); s1.push(7);
    s.push(3); 
    s.push(4); 
    s.push(5); 
  
    cout << "The stack is : "; 
    display(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\nAfter popping s.pop() : "; 
    s.pop(); 
    display(s); 

  cout<<'\n'<<s1.top()<<" "<<s.top();
    return 0; 
} 
