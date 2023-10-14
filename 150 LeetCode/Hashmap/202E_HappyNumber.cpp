//Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.


//https://leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
using namespace std;
int nextNumber(int n)
{
    int newNumber = 0;
    while (n != 0)
    {
        int num = n % 10;//last digit of number
        newNumber += num * num;
        n = n / 10;
    }
    return newNumber;
}
bool isHappy(int n)
{
    unordered_set<int> set;
    while (n != 1 && !set.count(n))//set.count returns 0 or 1 as the set contains unique elements only
    {
        set.insert(n);
        n = nextNumber(n);
        cout << n << " ";
    }
    return n == 1;
}

int main()
{
    int n = 19;

    cout << isHappy(n);

    return 0;
}