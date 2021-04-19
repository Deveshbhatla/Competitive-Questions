//Given a set of intervals, merge the overlapping intervals. Eg. {1,2} {2,5}={1,5}
#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int s, e;
};

bool mycomp(Interval a, Interval b) //Increasing order of start time, can also use decreasing order of end time
{
    return a.s < b.s;
}

void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr + n, mycomp); //{2,7}, {3,15},{5,10}, {18,30}
    int result = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[result].e >= arr[i].s)
        {
            arr[result].e = max(arr[result].e, arr[i].e);
            arr[result].s = min(arr[result].s, arr[i].s);
        }
        else
        {
            result++;
            arr[result] = arr[i];
        }
    }
    for (int i = 0; i <= result; i++)
        cout << "{" << arr[i].s << ", " << arr[i].e << "} ";
}

int main()
{
    Interval arr[] = {{5, 10}, {3, 15}, {18, 30}, {2, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);

    return 0;
}