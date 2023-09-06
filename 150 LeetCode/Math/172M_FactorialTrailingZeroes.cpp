// Given an integer n, return the number of trailing zeroes in n!.
// Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

//We can dividet the number by 5 and then add the remainder to the count
// 100 -> 24 (100/5 = 20, then 20/5 = 4; 20+4)
// 10 -> 2 (10/2 = 2, then 2/5 = 0; 2+0)
// 24 -> 4 (24/5 = 4, then 4/5 = 0; 4+0)
// 25 -> 6 (25/5 = 5, then 5/5 = 1; 5+1)
// 200 -> 49 (200/5 = 40, 40/5 = 8, 8/5 = 1; 40+8+1)

// https://leetcode.com/problems/palindrome-number/
#include<bits/stdc++.h>
using namespace std;
int FactorialTrailingZeroes(int n)
{
    int count=0;
    while(n>=5)
    {
        count+=n/5;
        n/=5;
    }
    return count;
}
int main()
{
    int n=25;
    cout<<FactorialTrailingZeroes(n);
    return 0;
}