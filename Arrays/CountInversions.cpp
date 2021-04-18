#include <bits/stdc++.h>
using namespace std;

int countInversionsNaive(int arr[], int n) //O(n2)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                res++;
        }
    }
    return res;
}

int countAndMerge(int arr[], int l, int m, int r)//using merge sort
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            res = res + (n1 - i);
        }
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
    return res;
}

int countInversionsEfficient(int arr[], int l, int r) //O(nlogn)
{
    int res = 0;
    if (l < r)
    {
        int m = (r + l) / 2;
        res += countInversionsEfficient(arr, l, m);
        res += countInversionsEfficient(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main()
{

    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total number of Inversions: " << countInversionsNaive(arr, n);
    cout<<countInversionsEfficient(arr,0,n-1);
    return 0;
}