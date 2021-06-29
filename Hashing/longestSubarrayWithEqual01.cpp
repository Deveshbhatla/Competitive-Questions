#include <bits/stdc++.h>
using namespace std;

//gives the Longest Subrarray With Equal number of 0 and 1
int LongestSubrarrayWithEqual0and1(int arr[], int n) //O(n2)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count_0 = 0, count_1 = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                count_0++;
            else
                count_1++;
            if (count_1 == count_0)
                res = max(res, count_0 + count_1);
        }
    }

    return res;
}
//gives the Longest Subrarray With Equal number of 0 and 1 using unordered map
int LongestSubrarrayWithEqual0and1Efficient(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;

    unordered_map<int, int> um;
    int sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            res = i + 1;

        if (um.find(sum + n) != um.end())
        {
            if (res < i - um[sum + n])
                res = i - um[sum + n];
        }
        else
            um[sum + n] = i;
    }

    return res;
}

int main()
{
    int arr[] = {0, 0, 0, 1, 1, 0, 1, 0}, n = 8;

    cout << LongestSubrarrayWithEqual0and1(arr, n);
        cout << LongestSubrarrayWithEqual0and1Efficient(arr, n);

}