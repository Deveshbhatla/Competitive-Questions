#include<bits/stdc++.h>
using namespace std;

//This function returns the precedenece of the operators
int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1; 
}
void infixToPostfix(string s)
{
    stack<char> st;
    st.push('N');
    int l=s.length();
    string new_string;

    for(int i=0; i<l;i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))// if the character is an operand
            new_string+=s[i];

        else if(s[i]=='(')
            st.push('(');


        else if(s[i]==')')  //pop out until ) is encountered
        {
            while(st.top()!='N' &&st.top()!='(')
            {
                char c=st.top();
                st.pop();
                new_string+=c;
            }
            if(st.top()=='(')
            {
                char c=st.top();
                st.pop();
            }
        }

        else// if an operator is encountered
        {
            while(st.top() != 'N' && precedence(s[i]) <= precedence(st.top()))
            {
                char c = st.top();
                st.pop();
                new_string += c;
            }
            
            st.push(s[i]);    
        }
        
    }

        // Pop all the remaining elements from the stack
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        new_string += c;
    }
    
    cout<<new_string<<'\n';

}
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    
    infixToPostfix(exp);
    
    return 0;
}