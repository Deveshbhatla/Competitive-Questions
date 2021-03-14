#include<bits/stdc++.h>
using namespace std;
int missing(int arr[],int n)
{
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]+1!=arr[i+1])
        return arr[i]+1;
    }
    return 0;
}
//XOR Method
int Missing_XOR(int arr[], int n)
{
    int x1 = arr[0];
    int x2 = 1;
    for (int i = 1; i < n; i++)
        x1 = x1 ^ arr[i];
 
    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;
 
    return (x1 ^ x2);
}
int main()
{
    int arr[]={1,5,3,4};
    cout<<missing(arr,4);
    cout<<Missing_XOR(arr, 4);
    return 0;
}