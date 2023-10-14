// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.

// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;

    for (auto x : strs)
    {
        string word = x;
        sort(word.begin(), word.end());// so that tan=nat, and eat=tea=ate
        mp[word].push_back(x);
    }

    //pushing the value of map into a vector<vector<string>>
    vector<vector<string>> ans;
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}

int main()
{
    vector<string>str {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result=groupAnagrams(str);
    //Expected output: [["bat"],["tan","nat"],["eat","tea","ate"]]

    for(auto i:result)
    {
        for(auto x:i)
            cout<<"[\""<<x<<"\"]";
    }
    return 0;
}