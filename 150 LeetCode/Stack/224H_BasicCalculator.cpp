// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

//Input: s = "(1+(4+5+2)-3)+(6+8)"
//Output: 23
//https://leetcode.com/problems/basic-calculator/

#include<bits/stdc++.h>
using namespace std;
int calculate(string s) {
    
     int n=s.length();
        stack<int> st;

        int number=0;
        int result=0;
        int sign =1;
        
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
                number=number*10+(s[i]-'0');
            
            else if(s[i]=='+')
            {
                result+=number*sign;
                number=0;
                sign=1;
            }
            else if(s[i]=='-')
            {
                result+=number*sign;
                number =0;
                sign=-1;
            }
            else if(s[i]=='(')
            {
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                result+=number*sign;
                number = 0;

                int stack_sign = st.top();
                st.pop();
                int last_result = st.top();
                st.pop();

                result *= stack_sign;
                result += last_result;
            }
        }
        result += number*sign;
        return result;

}

int main()
{
    string s="(1+(4+5+2)-3)+(6+8)";
    cout<<calculate(s);
    return 0;
}