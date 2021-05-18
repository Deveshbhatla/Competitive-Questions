//count distinct elements in both the arrays combined if a{1,2,3} & b{2,3,4} output is :4{1,2,3,4}
#include<bits/stdc++.h>
using namespace std;

int Union(int arr1[],int m, int arr2[],int n)
{
    unordered_set <int> h(arr1,arr1+m);
    for (int  i = 0; i < n; i++) 
       h.insert(arr2[i]);  
       //or
    unordered_set<int> unorderedSet;
     for(int i=0;i<m;i++)
        unorderedSet.insert(arr1[i]);
    for(int i=0;i<n;i++)
        unorderedSet.insert(arr2[i]);
    
    return unorderedSet.size();
}

int main()
{
    int arr1[] = {1,2,3};
    int arr2[] = {2,3,4};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout <<"number of distinct common elements in Union: "<< Union(arr1, m, arr2, n);
    return 0;
}