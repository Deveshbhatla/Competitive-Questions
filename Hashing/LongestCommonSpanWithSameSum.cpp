#include <bits/stdc++.h>
using namespace std;
int maxCommonSum(bool arr1[], bool arr2[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j < n; j++)
        {
            sum1 += arr1[j];
            sum2 += arr2[j];
            if (sum1 == sum2)
                res = max(res, j - i + 1);
        }
    }
    return res;
}
/*temp=arr1[i]-arr2[i]
temp map has 0 for same elements in both the arrays
temp has value -1 when arr1[i]=0 and arr2[i]=1
temp has value 1 when arr1[i]=1 and arr2[i]=0
*/
int maxCommonSumEfficient(bool arr1[], bool arr2[], int n)
{
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = arr1[i] - arr2[i];

    unordered_map<int, int> uM;

    int sum = 0;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
            res = i + 1;

        if (uM.find(sum) != uM.end())
            res = max(res, i - uM[sum]);

        else
            uM[sum] = i;
    }

    return res;
}
int main()
{
    bool arr1[] = {0, 1, 0, 0, 0, 0}, arr2[] = {1, 0, 1, 0, 0, 1};
    int n = 6;
    cout << maxCommonSum(arr1, arr2, n);
    cout << maxCommonSumEfficient(arr1, arr2, n);

    return 0;
}