#include<bits/stdc++.h>
using namespace std;


void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
   
}

stack<int> sortStack(stack<int> s);

int main()
{
int t;
cin>>t;
while(t--)
{
	stack<int>s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
    	int k;
    	cin>>k;
    	s.push(k);
	}
	stack<int> ans=sortStack(s);
	printStack(ans);
	cout<<endl;
}
}// } Driver Code Ends

//My code starts from here

stack<int> sortStack(stack<int> s)
{
    stack<int> temp_stack; 
    while (!s.empty()) 
    { 
        int temp = s.top(); 
        s.pop(); 
        while (!temp_stack.empty() && temp_stack.top() > temp) 
        { 
            s.push(temp_stack.top()); 
            temp_stack.pop(); 
        } 
        temp_stack.push(temp); 
    } 
    return temp_stack; 
    
}