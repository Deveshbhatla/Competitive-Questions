//Given an array of names of candidates in an election. A candidate name in array represents a vote casted to the candidate. 
//You need to find the candidate with maximum votes recieved in the election.
//It may happen that two or more candidates may have the same votes, in that case you need to return the name of the candidate which comes first lexicographically in dictionary.
#include <bits/stdc++.h>
using namespace std;

string TieBreak(string names[], int n)
{
     map<string,int> map;
    for(int i=0;i<n;i++)
    {
        map[names[i]]++;
    }
    int max=0;
    string winner;
    for(auto itr=map.begin();itr!=map.end();itr++)
    {
        if(itr->second>max)
        {
            max=itr->second;
            winner=itr->first;
        }
    }
        return winner;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        
        string names[n];
        for(int i = 0; i < n; i++)
            cin>>names[i];
        cout << TieBreak(names,n) <<endl; 
    }
}
