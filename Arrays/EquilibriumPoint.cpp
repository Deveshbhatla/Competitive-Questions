#include <bits/stdc++.h>
using namespace std;
bool EquilibriumPointNaive(int arr[], int n) //O(n2)
{
    for (int i = 0; i < n; i++)
    {
        int l_sum = 0, r_sum = 0;

        for (int j = 0; j < i; j++)
            l_sum += arr[j];

        for (int j = i + 1; j < n; j++)
            r_sum += arr[j];

        if (l_sum == r_sum)
            return true;
    }

    return false;
}

bool EquilibriumPointEfficient(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int l_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (l_sum == sum - arr[i])
            return true;

        l_sum += arr[i];

        sum -= arr[i];
    }

    return false;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6}, n = 6;
    cout << EquilibriumPointNaive(arr, n) ? "true" : "false";
    cout << '\n';
    cout << EquilibriumPointEfficient(arr, n) ? "true" : "false";
    return 0;
}