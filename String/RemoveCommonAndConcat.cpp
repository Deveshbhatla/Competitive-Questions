#include<bits/stdc++.h>
using namespace std;
string concatenatedString(string s1, string s2) 
    { 
        int count[26] = {0};

        for(int i = 0; i < s1.size(); i++)
        {
        count[s1[i]-'a'] = 1;
        }
        
        for(int i = 0; i < s2.size(); i++)
        {
            if(count[s2[i]-'a'] == 1 || count[s2[i]-'a'] == 2)
            {
                count[s2[i]-'a'] = 2;
            }
            else
            {
                count[s2[i]-'a'] = 3;
            }
        }
        
        string res="";
        s1 += s2;
        for(int i = 0; i < s1.size(); i++)
        {
            if(count[s1[i]-'a'] == 1 || count[s1[i]-'a'] == 3)
            {
                res += s1[i];
            }
        }
        
        return res;
    }
int main() 
{ 
    string s1 = "aacdb";
    string s2 = "gafd";
    cout<<concatenatedString(s1,s2); 
    return 0; 
} 