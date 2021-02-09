#include<iostream>
#include<vector>
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
