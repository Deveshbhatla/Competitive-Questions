#include<bits/stdc++.h>
using namespace std;
void Frequencies(int arr[],int n)
{
    int frequency=1,i=1;
    while(i<n)
    {
        while(i<n&&arr[i]==arr[i-1])
        {
            frequency++;
            i++;
        }
        cout<<arr[i-1]<<": "<<frequency<<'\n';
        i++;
        frequency=1;
    }
    if(n==1||arr[n-1]!=arr[n-2])//check for last element
    cout<<arr[n-1]<<": "<<1;
}
int main()
{
    int arr[]={10,10,10,10,30,30,40,50,50,50},n=10;
    Frequencies(arr,n);
    return 0;
}