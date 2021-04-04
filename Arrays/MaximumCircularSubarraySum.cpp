#include <bits/stdc++.h>
using namespace std;
int maximumCircularSubarraySumNaive(int arr[], int n) //O(n2)
{
    int result = arr[0];
    for (int i = 0; i < n; i++)
    {
        int current_max = arr[i]; //maximum sum that you can obtain when ith element is the beginning of the subarray
        int current_sum = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            current_sum += arr[index];
            current_max = max(current_max, current_sum);
        }
        result = max(result, current_max);
    }
    return result;
}
int MaxSum(int arr[], int n)//Kadane's algorithm for finding the maximum sum of non-circular subarray 
{
	int res = arr[0];
	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}
	
	return res;
}

int maximumCircularSumSubarrayEfficient(int arr[],int n)//O(n)
{
	int max_normal_subarray = MaxSum(arr, n);

	if(max_normal_subarray < 0)
		return max_normal_subarray;

	int arr_sum = 0;

	for(int i = 0; i < n; i++)//Inversing the elements. Maximum sum of inverse elements is minimum sum of normal elements
	{
		arr_sum += arr[i];
		arr[i] = -arr[i];
	}
	int max_circular = arr_sum + MaxSum(arr, n);
	return max(max_circular, max_normal_subarray);
}

int main()
{
    int arr[] = {5, -2, 3, 4}, n = 4;
    cout << maximumCircularSubarraySumNaive(arr, n)<<" ";
    cout<<maximumCircularSumSubarrayEfficient(arr,n);
    return 0;
}