#include<bits/stdc++.h>
using namespace std;
int rem_Duplicates_naive(int arr[],int n)// O(n): time and space
{
    int temp[n],res=1;
    temp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        if(temp[res-1]!=arr[i])
        {
            temp[res]=arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++)
    {
        arr[i]=temp[i];
    }
    return res;
}

int rem_Duplicates_Efficient(int arr[],int n)//O(n)time O(1) space
{
    int res=1;
    for (int i=1;i<n;i++)
    {
        if(arr[res-1]!=arr[i])
        {
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}
int main()
{
    int n;
    int arr[]={ 1,2,2,2,3,4};
    n=sizeof(arr)/sizeof(arr[0]);
     for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<'\n';
    int new_size=rem_Duplicates_naive(arr,n);
    int new_size_efficeient=rem_Duplicates_Efficient(arr,n);

        for(int i=0;i<new_size_efficeient;i++)
    {
        cout<<" "<<arr[i];
    }
    return 0;
}