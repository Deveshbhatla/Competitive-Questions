//Given a sorted array with repetition and an element x, we need to find index of first occurrence of x.
#include<bits/stdc++.h>
using namespace std;
int firstOccurence(int arr[],int n,int x)//O(logn)
{
    int low =0, high = n-1;
    while(low<=high) //binsry search 
    {
        int mid=(low+high)/2;
        if(arr[mid]>x)
            high=mid+1;
        else if(arr[mid]<x)
            low=mid+1;
        else
        {
            if(mid==0||arr[mid-1]!=arr[mid])
            {
                return mid;
            }
            else
                high =mid-1;
        }    
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,5,5,5,5,8,5,4,3,2,2},n=15,x=5;
    cout<<"Found at: "<<firstOccurence(arr,n,x);
    return 0;
}