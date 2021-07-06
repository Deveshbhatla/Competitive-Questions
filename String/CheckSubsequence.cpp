//no of subsequences of length of string n is 2^n. Characters should be in same order
#include <bits/stdc++.h>
using namespace std;

//Time: O(n+m) space: O(1)
bool SubsequenceIterative(string &str1, string &str2, int n, int m)
{
    if (m > n)
        return false;

    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (str1[i] == str2[j])
            j++;
    }
    return j == m;
}
bool SubsequenceRecursive(string &str1, string &str2, int n, int m)
{
    if (m == 0)
        return true;

    if (n == 0)
        return false;

    if (str1[n - 1] == str2[m - 1])
        return SubsequenceRecursive(str1, str2, n - 1, m - 1); //if matching reduce both m and n by 1

    else
        return SubsequenceRecursive(str1, str2, n - 1, m); // if not matching reduce n by 1
}
int main()
{
    string str1 = "deveshbhatla", str2 = "db";
    int n = str1.length(), m = str2.length();

    cout << SubsequenceIterative(str1, str2, n, m);
    cout << SubsequenceRecursive(str1, str2, n, m);
}