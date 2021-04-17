#include<bits/stdc++.h>
using namespace std;

int getMinimumDifferenceNaive(int arr[], int n)
{
    int res = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0;j<i;j++)
        {
            res = min(res, abs(arr[i] - arr[j]));
        }
    }
    return res;
}
int getMinuminDifferenceEfficient(int arr[],int n)
{
    int res=INT_MAX;
    sort(arr,arr+n);
    for(int i=1;i<5;i++)
    {
        res=min(res,arr[i]-arr[i-1]);
    }
    return res;
}

int main() 
{
	int arr[5]={90,85,1,8,4};
	cout<<getMinimumDifferenceNaive(arr, 5 )<<'\n';
    cout<<getMinuminDifferenceEfficient(arr,5);
	return 0;
}