#include <bits/stdc++.h>
using namespace std;

bool sortIncreasingValueByWeight(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;

    return r1 > r2;
}
double fractionalKnapsack(int weight, pair<int, int> arr[], int n)
{
    sort(arr, arr + n, sortIncreasingValueByWeight);
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].second <= weight)
        {
            result += arr[i].first;
            weight = weight - arr[i].second;
        }
        else
        {
            result += arr[i].first * ((double)weight / arr[i].second);
            break;
        }
    }

    return result;
}
int main()
{
    //(value,weight)
    pair<int, int> arr[] = {make_pair(120, 30), make_pair(100, 20), make_pair(60, 10)};

    int n = 3, W = 50;
    cout << fractionalKnapsack(W, arr, n);

    return 0;
}