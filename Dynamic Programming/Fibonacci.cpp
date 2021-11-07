
#include <bits/stdc++.h>
using namespace std;

int memo[1000000];

int fibonacciRecursion(int n)//O(2^n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

//Memoization(Top down)
int fibonacciMemoization(int n)//O(n)
{
    if (memo[n] == -1)
    {
        int result;
        if (n == 0 || n == 1)
            result = n;
        else
            result = fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2);

        memo[n] = result;
    }
    return memo[n];
}

//Tabulation(Bottom up)
int fibonacciTabulation(int n)
{
    int f[n+1];
    f[0]=0, f[1]=1;

    for (int i = 2; i <=n; i++)
        f[i]=f[i-1]+f[i-2];

    return f[n];    
    
}
 
int main()
{
    memset(memo, -1, sizeof(memo));

    int n = 5;
    cout << fibonacciTabulation(8);
}