// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

//https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {

    stack<int> s;

    for(int i=0;i<tokens.size();i++)
    {
        string tempString= tokens[i];

        if(tempString=="+")
        {
            int firstNumber=s.top();
            s.pop();
            int secondNumber=s.top();
            s.pop();
            s.push(firstNumber+secondNumber);
        }
        else if(tempString=="-")
        {
            int firstNumber=s.top();
            s.pop();
            int secondNumber=s.top();
            s.pop();
            s.push(secondNumber-firstNumber);//the integer popped second from the stack is the one to be considered first in the order, and the one popped first is to be considered second in the order
        }
        else if(tempString=="*")
        {
            int firstNumber=s.top();
            s.pop();
            int secondNumber=s.top();
            s.pop();
            s.push(firstNumber*secondNumber);
        }
        else if(tempString=="/")
        {
            int firstNumber=s.top();
            s.pop();
            int secondNumber=s.top();
            s.pop();
            s.push(secondNumber/firstNumber);//the integer popped second from the stack is the one to be considered first in the order, and the one popped first is to be considered second in the order
        }
        else
        {
            s.push(stoi(tempString));
        }
    }

    return s.top();   
    
}

int main()
{
    vector<string> vec= {"4","13","5","/","+"};
    cout<<evalRPN(vec);//6    
    return 0;
}