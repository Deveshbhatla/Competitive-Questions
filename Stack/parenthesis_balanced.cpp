#include<bits/stdc++.h>
using namespace std;
bool matching(char a,char b)
{
    return(
    ( a=='(' && b==')' )||
    ( a=='[' && b==']' )||
    ( a=='{' && b=='}' )
    );
}
bool isbalanced(string str)
{
    stack <char> s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            s.push(str[i]);
        else
        {
            if(s.empty()==true)
                return false;
            else if(matching(s.top(),str[i])==false)
                return false;
            else
                s.pop();
        }

    }
     return (s.empty());// return true if stack is empty same as return(s.empty()==true))
}

//Alternate method using switch case
bool isBalancedExp(string exp) 
{
   stack<char> s;
   char x;
   for (int i=0; i<exp.length(); i++) 
   {
      if (exp[i]=='('||exp[i]=='['||exp[i]=='{') 
      {
         s.push(exp[i]);
         continue;
      }

      if (s.empty())
         return false;
      switch (exp[i]) 
      {
      case ')':
         x = s.top();
         s.pop();
         if (x=='{' || x=='[')
            return false;
         break;
      case '}':
         x = s.top();
         s.pop();
         if (x=='(' || x=='[')
            return false;
         break;
      case ']':
         x = s.top();
         s.pop();
         if (x =='(' || x == '{')
            return false;
         break;
      }
   }
   return (s.empty());
}

int main()
{
    string str = "{()}[]"; 
    
    if (isbalanced(str)) // same for the other method
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 

    return 0; 
}