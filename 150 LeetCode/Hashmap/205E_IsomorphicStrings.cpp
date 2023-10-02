// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character, but a character may map to itself.

// https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    map<char, char> s1;
    map<char, char> t1;

    for (int i = 0; i < s.size(); i++)
    {
        //filling the s1 map and checking if the elements of the map are similar to t
        if (s1[s[i]] == 0)
            s1[s[i]] = t[i];
        else if (s1[s[i]] != t[i])
            return false;

        // filling the t1 map and checking if the elements of the map similar to s
        if (t1[t[i]] == 0)    
            t1[t[i]] = s[i];
        else if (t1[t[i]] != s[i])
            return false;
    }
    
    return true;
}

int main()
{
    string s = "bbbaaaba";
    string t = "aaabbbba";

    string result = isIsomorphic(s, t) ? "true" : "false";
    cout << result;
    return 0;
}