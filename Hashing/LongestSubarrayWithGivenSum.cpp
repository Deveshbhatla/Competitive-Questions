#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSum(int arr[], int n, int sum)
{
    int prefixSum = 0;
    unordered_set<int> us;
    us.insert(0);
    for(int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if(us.find(prefixSum - sum) != us.end())
          return 1;
        us.insert(prefixSum);
    }
    return 0;
}

int main()
{
    int arr[] = {1,2,3,4,5},n=5,sum=6;
    cout << longestSubarrayWithSum(arr, n, sum);
    
}