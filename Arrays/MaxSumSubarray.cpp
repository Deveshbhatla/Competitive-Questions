//Find maximum sum of subarray, Kadane's Algorithm
#include<bits/stdc++.h>
using namespace std;
int maxSumNaive(int arr[],int n)//O(n2)
{
    int result =arr[0];

    for(int i=0;i<n;i++)
    {
        int current=0;

        for(int j=i;j<n;j++)
        {
            current+=arr[j];
            result=max(current,result);
        }
    }
    return result;
}
int maxSumEfficient(int arr[],int n)//Kadane's Algorithm O(n)
{
    int result = arr[0];
	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);
		result = max(maxEnding, result);
	}
	return result;
}
int main()
{
    int arr[]={1,-2,3,-1,2},n=5;
    cout<<maxSumNaive(arr,n)<<" ";
    cout<<maxSumEfficient(arr,n);
    return 0;
}