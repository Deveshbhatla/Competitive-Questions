#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=1;i<=8;i++)
        v.push_back(i);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    // v.push_back(8);

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<'\n';

    for(int x:v)
        cout<<x<<" ";
    cout<<'\n';

    vector<int> :: iterator itr;
    for(itr = v.begin(); itr!=v.end(); itr++)
        cout<<*itr<<" ";
    
    cout<<'\n';

    for(auto itr2 = v.begin(); itr2!=v.end();itr2++)
        cout<<*itr2<<" ";
    return 0;
}

//Some basic programs for vectors
int findFrequency(vector<int> v, int x){
    
    int freq = count(v.begin(), v.end(), x);
    return freq;
    
}
vector<int> sortVector(vector<int>v)
{
   sort(v.begin(),v.end());
    return v;
}
vector<int> reverseVector(vector<int>v)
{
    reverse(v.begin(), v.end()); 
    return v;
}
void eraseAt(vector<int> &V, int pos)
{
    vector<int> :: iterator itr=V.begin();
    itr+=pos;
    V.erase(itr);
 
    
}

void eraseInRange(vector<int> &V, int start, int end)
{
    vector<int> :: iterator itr1=V.begin();
     vector<int> :: iterator itr2=V.begin();
    itr1+=start;
        itr2+=end;

    V.erase(itr1,itr2);
}

void clearAll(vector<int> &V)
{
   V.clear();
    
}
vector<int> list_less_than_k(vector<int> a,int n,int k)
{
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        if(a[i]<k)
        v.push_back(a[i]);
    }
    return v;
}
