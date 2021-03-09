#include<bits/stdc++.h>
using namespace std;

vector<int> leftRotateK(vector<int> v,int k)
{
	int rotL=k%v.size(); 
    rotate(v.begin(), v.begin()+rotL, v.end()); 
	return v;
}

int main () { 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        int k;
        cin>>k;
        
        vector<int> ans=leftRotateK(v,k);
        
        for(auto x:ans)
        cout<<x<<" ";
        
        cout<<endl;
    }
  

  
return 0; 
} 
  