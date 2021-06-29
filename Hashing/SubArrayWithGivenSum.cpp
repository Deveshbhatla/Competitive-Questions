#include <bits/stdc++.h>
using namespace std;
bool isSubarrayContainsGivenSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        int currentSum = 0;
        for (int j = 0; j < n; j++)
        {
            currentSum += arr[j];
            if (currentSum == sum)
                return true;
        }
    }
    return false;
}
bool isSubarrayEfficient(int arr[], int n, int sum) //create prefix sum Time:O(n) space O(n)
{
    unordered_set<int> s;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (prefixSum == sum)
            return true;
        prefixSum += arr[i];
        if (s.find(prefixSum - sum) != s.end())
            return true;
        s.insert(prefixSum);
    }
    return false;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}, n = 8, sum = 21;
    cout << isSubarrayContainsGivenSum(arr, n, sum);
    cout << isSubarrayEfficient(arr, n, sum);

    return 0;
}
