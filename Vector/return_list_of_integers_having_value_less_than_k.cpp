#include<bits/stdc++.h>
using namespace std;

vector<int> fun(int arr[], int n, int k)
{   
 
    vector<int> V;
    
    for(int i = 0; i < n; i++)
    {   
        if (arr[i] < k) 
            V.push_back(arr[i]);
    }
    
    return V;
}

int main()
{
    // Input
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 8;
    
    for(auto x:fun(arr, n, k))
        cout<<x<<" ";
    
    return 0;
}
