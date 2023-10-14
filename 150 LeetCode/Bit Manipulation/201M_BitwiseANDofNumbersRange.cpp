// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

// https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <bits/stdc++.h>
using namespace std;
int rangeBitwiseAnd(int left, int right)
{

    // if (left == right)
    //     return left;

    // for (long long int i = left; i <= right; i++)
    // {
    //     left &= i;
    //     if (left == 0)
    //         return left;
    // }
    // return left;


    // constant time
         int ans = 0;

    for(int i=31;i>=0;i--)
    {
        if((left & (1 << i)) != (right & (1 << i)))
            break;

        else
            ans |= ((left & (1 << i)));

    }
    return ans;
}

int main()
{
    int left = 5, right = 7;
    cout << rangeBitwiseAnd(left, right);
    return 0;
}