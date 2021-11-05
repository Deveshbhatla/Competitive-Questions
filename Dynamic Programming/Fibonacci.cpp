//Memoization

#include <bits/stdc++.h>
using namespace std;

int memo[1000000];

int fibonacciRecursion(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int fibonacciDynamic(int n)
{
    if (memo[n] == -1)
    {
        int result;
        if (n == 0 || n == 1)
            result = n;
        else
            result = fibonacciDynamic(n - 1) + fibonacciDynamic(n - 2);

        memo[n] = result;
    }
    return memo[n];
}

int main()
{
    memset(memo, -1, sizeof(memo));

    int n = 5;
    cout << fibonacciDynamic(8);
}