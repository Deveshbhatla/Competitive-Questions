//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.

//https://leetcode.com/problems/ransom-note/

#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {

        map <char,int> mp;

        //store the characters of magazine and their occurences in map
        for(int i=0;i<magazine.size();i++)
        {
            mp[magazine[i]]++;
        }

        //if character of ransomeNote is same as magazine then reduce the count by one
        //If the size is 0 then there was no character of ransomNote present in magazine

        for(int i=0;i<ransomNote.size();i++)
        {
            if(mp[ransomNote[i]]>0)
                mp[ransomNote[i]]--;
            else 
                return false;
        }
        
        return true;
    }

int main()
{
    string ransomNote="aa";
    string magazine="aab";

    string result=canConstruct(ransomNote,magazine)?"true":"false";
    cout<<result;
    return 0;
}