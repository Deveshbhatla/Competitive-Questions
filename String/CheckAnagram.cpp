// A string is an anagram of another if both the strings have same letters ie.
//if every letter appears in the first string should appear in the second string
#include <bits/stdc++.h>
using namespace std;
const int CHAR=256;

//O(nlogn)
bool checkAnagram(string &str1, string &str2)
{
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

bool checkAnagramEfficient(string &s1, string &s2)
{
    int n1 = s1.length(); 
    int n2 = s2.length(); 
    if (n1 != n2) 
        return false; 
    
    int count[CHAR]={0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    
    for(int i=0;i<CHAR;i++){
        if(count[i]!=0)return false;
    }
    return true;
}

int main()
{
    string str1 = "bbaabababababa";
    string str2 = "bbaabababaabab";

    cout << checkAnagram(str1, str2);
    cout << checkAnagramEfficient(str1, str2);

    return 0;
}