//To check if S is subsequence of t
#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {

    int substringPointer=0;
    for (int i = 0; i < t.length() && substringPointer < s.length(); i++)
        if (s[substringPointer] == t[i])
            substringPointer++;
 
    return (substringPointer == s.length());

}
int main()
{
    string s = "abc";
    string t="ahbgdc";
    cout<<isSubsequence(s,t);
    return 0;
}
