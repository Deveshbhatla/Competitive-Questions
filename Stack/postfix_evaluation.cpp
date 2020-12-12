#include<bits/stdc++.h>
using namespace std;
int Postifx(char *string)//stiring literal
{
        stack<int> s;
    for(int i=0;string[i];i++)// same as for(int i = 0; string[i] != 0; i++)
    {
        if(isdigit(string[i]))
             s.push(string[i]-'0');

        else
        { 
            int val1 = s.top();
            s.pop();
            
            int val2 = s.top();
            s.pop();
            
            switch (string[i]) 
            { 
                case '+': s.push(val2 + val1); break; 
                case '-': s.push(val2 - val1); break; 
                case '*': s.push(val2 * val1); break; 
                case '/': s.push(val2/val1); break; 
            } 
        }

    }
        return s.top();
}
int main()
{
    char expression[] = "231*+9-"; 
    cout<<"Answer is:  "<< Postifx(expression); 
    return 0; 
}