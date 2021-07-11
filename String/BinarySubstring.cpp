//Function to count the number of substrings that start and end with 1
#include<bits/stdc++.h>
using namespace std;

//count all ones and then apply nC2. taking 2 ones from all ones
long binarySubstring(int n, string a){
        
        // Your code here
        long count=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='1')
            count++;
        }
        return count*(count-1)/2;//nC2
        
    }
    int main()
    {
        int n=4;
        string s="1111";
        cout<<binarySubstring(n,s);
        return 0;
    }