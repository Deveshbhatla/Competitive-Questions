#include<bits/stdc++.h>
using namespace std;
int findOddOccurrences(int arr[],int n)//O(n2)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
                count++;
        }
        if(count%2!=0)
            return arr[i];
    }
    return 0;
}
int findOdd_Efficient(int arr[], int n)//O(n)
{
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        result = result ^ arr[i];
    }
    return result;
}
int main()
{
    int arr[]={1,1,1,2,3,3,2,5,4,1,4}, n=11;	
    cout<<findOddOccurrences(arr,n);
    cout<<findOdd_Efficient(arr,n);
    return 0;
}