#include<bits/stdc++.h>
using namespace std;
int findSum(string str)
    {
    	str = str + " ";
        int sum = 0;
        string s = "";
        
        for(int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            
            if(isdigit(ch)) 
                s += ch;
                
            else if(s.length() > 0)
            {
                sum += stoi(s);//string to integer
                s = "";//reset temp string
                
            }
        }
        return sum;
    }
    int main() 
{ 
    string s = "1acdb45";
    cout<<findSum(s); 
    return 0; 
} 