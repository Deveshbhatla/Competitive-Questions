#include <bits/stdc++.h>
using namespace std;

void NByKOccurencesNaive(int arr[], int n, int k) //O(nlogn)
{
    sort(arr, arr + n);
    int i = 1, count = 1;
    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            count++;
            i++;
        }
        if (count > n / k)
            cout << arr[i - 1] << " ";
        count = 1;
        i++;
    }
}
void NByKOccurencesNaiveEfficient(int arr[], int n, int k) //O(n)
{
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    for (auto e : m)
        if (e.second > n / k)
            cout << e.first << " ";
}
//based on Boyer–Moore majority vote algorithm
void printNByKLarge_n(int arr[], int n, int k) //O(nk)
{
    unordered_map<int, int> um;

    for (int i = 0; i < n; i++)
    {
        if (um.find(arr[i]) != um.end())
            um[arr[i]]++;
        else if (um.size() < k - 1)
            um[arr[i]] = 1;
        else
            for (auto x : um)
            {
                x.second--;
                if (x.second == 0)
                    um.erase(x.first);
            }
    }
    for (auto x : um)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (x.first == arr[i])
                count++;
        }
        if (count > n / k)
            cout << x.first << " ";
    }
}

int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10, 10}, n = 7, k = 2;

    NByKOccurencesNaive(arr, n, k);
    NByKOccurencesNaiveEfficient(arr, n, k);
    printNByKLarge_n(arr, n, k);
}