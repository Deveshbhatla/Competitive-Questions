//union of sorted arrays without including the same element twice
#include <bits/stdc++.h>
using namespace std;

void UnionNaive(int a[], int b[], int m, int n) //O((m+n)*log(m+n))
{

    int c[m + n];
    for (int i = 0; i < m; i++)
        c[i] = a[i];
    for (int i = 0; i < n; i++)
        c[i + m] = b[i];
    sort(c, c + m + n);

    for (int i = 0; i < m + n; i++)
    {
        if (i == 0 || c[i] != c[i - 1])
            cout << c[i] << " ";
    }
}
void UnionEfficient(int a[], int b[], int m, int n) //O(m+n)
{

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j - 1] == b[j])
        {
            j++;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < m)
    {
        if (i == 0 || a[i] != a[i - 1])
            cout << a[i] << " ";
        i++;
    }
    while (j < n)
    {
        if (j == 0 || b[j] != b[j - 1])
            cout << b[j] << " ";
        j++;
    }
}
int main()
{
    int a[] = {3, 8, 10};
    int b[] = {2, 8, 9, 10, 15};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    UnionNaive(a, b, m, n);
    UnionEfficient(a, b, m, n);
    return 0;
}