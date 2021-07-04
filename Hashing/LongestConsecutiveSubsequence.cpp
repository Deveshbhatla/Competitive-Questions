#include <bits/stdc++.h>
using namespace std;
int LCS(int arr[], int n)
{
    sort(arr, arr + n);
    int res = 1, curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
            curr++;
        else
        {
            res = max(res, curr);
            curr = 1;
        }
    }
    res = max(res, curr);
    return res;
}

int LCSEfficient(int arr[], int n)//Time: O(n) 2n lookup
{
    unordered_set<int> us;
    int res = 0;
 
    for (int i = 0; i < n; i++)
        us.insert(arr[i]);
 
    for (int i = 0; i < n; i++) {
        if (us.find(arr[i] - 1) == us.end()) {
            int curr = 1;
            while (us.find(curr+arr[i]) != us.end())
                curr++;
                
            res = max(res, curr);
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 9, 3, 4, 2, 20}, n = 6;
    cout << LCS(arr, n);
        cout << LCSEfficient(arr, n);

    return 0;
}