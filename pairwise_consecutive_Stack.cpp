/*Given a stack of integers of size N, your task is to complete the function pairWiseConsecutive(), that checks whether numbers in the stack are pairwise consecutive or not. The pairs can be increasing or decreasing, and if the stack has an odd number of elements, the element at the top is left out of a pair. The function should retain the original stack content.

Only following standard operations are allowed on stack.

push(X): Enter a element X on top of stack.
pop(): Removes top element of the stack.
empty(): To check if stack is empty.*/
// { Driver Code Starts

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool pairWiseConsecutive(stack<int> s);

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        stack<int> s;
        int n, tmp;
        cin>>n;
        while(n--){
            cin>>tmp;
	        s.push(tmp);
	    }
	    if (pairWiseConsecutive(s))cout << "Yes" << endl;
	    else cout << "No" << endl;
	    /*while (s.empty() == false)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout<<endl;*/
    }
	return 0;
}
// } Driver Code Ends


//User function Template for C++

// your task is to complete the function
// function should return true/false or 1/0

//my code starts from here
bool pairWiseConsecutive(stack<int> s)
{
    stack<int> temp;
	int temp_size=0;
	while (!s.empty()) {
		temp.push(s.top());
		s.pop();
		temp_size++;
	}
	bool result = true;
	while (temp_size>1) 
	{
		int x = temp.top();
		temp.pop();
		int y = temp.top();
		temp.pop();
		if (abs(x - y) != 1)
		    result = false;
		s.push(x);
		s.push(y);
		temp_size--;
		temp_size--;
	}
	if (temp.size() == 1)
		s.push(temp.top());
	return result;
    
}