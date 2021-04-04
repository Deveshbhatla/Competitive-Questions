#include <bits/stdc++.h>
using namespace std;
int CurrentSumNaive(int arr[], int n, int sum)//O(n2)
{
    for (int i = 0; i < n; i++)
    {
        int current_sum = arr[i];
        for (int j = i+1; j < n; j++)
        {
            
            if (current_sum == sum)
            {
                cout << current_sum;//between i and j-1
                return 1;
            }
             if (current_sum > sum || j == n)
                break;
            current_sum += arr[j];
        }
    }
    return 0;
}
int subArraySumEfficient(int arr[], int n, int sum)//O(n)
{
    int current_sum = arr[0], start = 0;

    for (int end = 1; end <= n; end++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (current_sum > sum && start < end - 1)
        {
            current_sum = current_sum - arr[start];
            start++;
        }

        if (current_sum == sum)
        {
            cout << "Sum found between indexes " << start << " and " << end - 1;
            cout << " and the sum is: " << current_sum << '\n';
            return 1;
        }

        if (end < n) //adding the element to the current sum
            current_sum = current_sum + arr[end];
    }

    cout << "No subarray found";
    return 0;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23}, n = 8, sum = 23;
    cout << subArraySumEfficient(arr, n, sum)<<'\n';
    CurrentSumNaive(arr, n, sum);
    return 0;
}
