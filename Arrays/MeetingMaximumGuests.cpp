#include <bits/stdc++.h>
using namespace std;

int maxGuest(int arrival[], int departure[], int n)
{
    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int i = 1, j = 0, res = 1, curr = 1;
    while (i < n && j < n)
    {
        if (arrival[i] < departure[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        res = max(curr, res);
    }
    return res;
}

int main()
{
    int arrival[] = {900, 600, 700};
    int departure[] = {1000, 800, 730};
    int n = sizeof(arrival) / sizeof(arrival[0]);

    cout << maxGuest(arrival, departure, n);

    return 0;
}