//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    map<char, int> anagramMap;

    // add 1 to the map of a specific character
   for(auto i: s)
    anagramMap[i]++;
   
   //subtract 1 from the map for the specific character
   for(auto i:t)
    anagramMap[i]--;

    // if any element is not zero it means that it was extra hence return false
    for(auto x: anagramMap)
        if(x.second!=0)
            return false;
            
    return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";

    string result = isAnagram(s, t) ? "true" : "false";
    cout << result;
    return 0;
}