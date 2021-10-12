#include <bits/stdc++.h>
using namespace std;

bool sortByFinishTimeAscending(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

int maxActivities(pair<int, int> arr[], int n)
{
    sort(arr, arr + n, sortByFinishTimeAscending);

    int previous = 0;
    int result = 1;

    for (int current = 1; current < n; current++)
    {
        if (arr[current].first >= arr[previous].second)
        {
            result++;
            previous = current;
        }
    }
    return result;
}
int main()
{
    pair<int, int> arr[] = {make_pair(10, 25), make_pair(10, 20), make_pair(20, 30)};
    int n = 3;
    cout << maxActivities(arr, n);

    return 0;
}