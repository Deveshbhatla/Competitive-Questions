/*You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer Q denoting the number of queries.
A Query Q may be of 3 Types:
    1. 1 x (a query of this type means  pushing 'x' into the stack)
    2. 2 (a query of this type means to pop element from stack and print the poped element)
    3. 3 (a query of this type means to print the minimum element from the stack)
The second line of each test case contains Q queries seperated by space.*/

#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}

// } Driver Code Ends

//User function Template for C++

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
//My code starts from here

/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty())
        return -1;
    else
        return minEle;
    
}
/*returns poped element from stack*/
int _stack ::pop()
{
    if (s.empty()) 
        { 
            return -1; 
        } 
        int t = s.top(); 
        s.pop(); 
        if (t < minEle) 
        { 
            int k = minEle;
            minEle = 2*minEle-t;
            return k; 
        } 
        else
            return t; 
    
}
/*push element x into the stack*/
void _stack::push(int x)
{
       if (s.empty()) 
        { 
            minEle = x; 
            s.push(x); 
            return; 
        } 
          if (x < minEle) 
        { 
            s.push(2*x - minEle); 
            minEle = x; 
        } 
        else
           s.push(x);
    
}