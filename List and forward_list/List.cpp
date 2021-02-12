#include<iostream>
#include<list>
using namespace std;

int main()
{
        list<int> l;
    
    // Push two elements at back
    l.push_back(10);
    l.push_back(20); 
    
    // Push an element to front
    l.push_front(30);
    
    // Traverse and print elements
    for(auto x: l)
    {
        cout<<x<<" ";
    }
    
    return 0;
}
