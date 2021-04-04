//Sliding Window
#include <bits/stdc++.h>
using namespace std;

int sumOfKConsecutiveNaive(int arr[], int n, int k) //O((n-k)*k)
{
    int max_sum = INT_MIN;
    for (int i = 0; i + k - 1 < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++) //for each size of window
            sum += arr[j + i];
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

int sumOfKConsecutiveEfficient(int arr[], int n, int k) //O(n) Sliding Window Technique
{
    //sum of first window
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];

    int window_sum = max_sum;

    for (int i = k; i < n; i++)//compute the sum of remaining windows and find the maximum out of it
    {
        window_sum += arr[i] - arr[i - k]; //adding the next element and subtracting the previous element of the window 

        max_sum = max(window_sum, max_sum);
    }
    return max_sum;
}
int main()
{
    int arr[] = {1, 2, -9, 50, 4, -5, 80}, n = 7, k = 3;
    cout << sumOfKConsecutiveNaive(arr, n, k);
    cout<<sumOfKConsecutiveEfficient(arr,n,k);
    return 0;
}