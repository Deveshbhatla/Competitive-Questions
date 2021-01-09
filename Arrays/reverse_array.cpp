#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[],int n)
{
    int temp,low=0,high=n-1;
    while(low<high)
    {
        temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;high--;
    }

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={1,2,3,4,5};
    reverseArray(arr,sizeof(arr)/sizeof(arr[0]));
        
    return 0;
}