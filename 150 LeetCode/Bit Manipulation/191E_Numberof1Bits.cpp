// Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

// https://leetcode.com/problems/number-of-1-bits/

#include <bits/stdc++.h>
using namespace std;
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n != 0)
    {
        count += n % 2;
        n >>= 1; // shift 1 bit to right
    }
    return count;
}

int main()
{
    uint32_t n = 11;
    cout << hammingWeight(n);

    return 0;
}