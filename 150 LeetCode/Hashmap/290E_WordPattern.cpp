// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// https://leetcode.com/problems/word-pattern/

#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{

    unordered_map<char, string> mp;
    unordered_map<string, char> mp2;

    int j = 0;
    int i = 0;
    
    while (i < pattern.length() && j < s.length())
    {
        string str = "";
        //copy the contents of s in a new string
        while (j < s.length() && s[j] != ' ')
        {
            str += s[j];
            j++;
        }
        j++;

    // if map mp is not empty, then compare the contentsd of mp with str
        if (mp.count(pattern[i]))
            if (mp[pattern[i]] != str)
                return false;

    // if map m2 is not empty, then compare the string in m2 with the pattern
        if (mp2.count(str))
            if (mp2[str] != pattern[i])
                return false;
        
    // fill mp map => key=each letter of pattern, value=string str    
        mp[pattern[i]] = str;
    //fill mp2 map => key=str and value= each letter of pattern
        mp2[str] = pattern[i];
        i++;
    }


    if (j < s.length())
        return false;
    if (i < pattern.length())
        return false;

    return true;
}

int main()
{
    string pattern = "abba";
    string s = "dog cat cat fish";

    string result = wordPattern(pattern, s) ? "true" : "false";
    cout << result;
    return 0;
}