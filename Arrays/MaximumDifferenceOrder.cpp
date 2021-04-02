// Maximum of arr[j]-arr[i] such that j>i
#include<bits/stdc++.h>
using namespace std;
int maximumNaive(int arr[],int n)//O(n2)
{
    int maximumDifference=arr[1]-arr[0];
    for(int i=0;i<n-1; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            maximumDifference=max(maximumDifference,arr[j]-arr[i]);
        }
    }
    return maximumDifference;
}
int maximumEfficient(int arr[],int n)//O(n)
{
    int maximumDifference =arr[1]-arr[0],minimumValue=arr[0];
    for(int j=1;j<n;j++)
    {
        maximumDifference=max(maximumDifference,arr[j]-minimumValue);
        minimumValue=min(minimumValue,arr[j]);
    }
    return maximumDifference;
}
int main()
{
    int arr[]={1,2,5,10,5,3,8},n=7;
    cout<<maximumNaive(arr,n)<<"    ";
    cout<<maximumEfficient(arr,n);
    return 0;
}