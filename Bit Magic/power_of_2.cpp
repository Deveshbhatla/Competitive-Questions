#include<bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)// Naive Solution
{
    if(n==0)
        return false;
    while (n!=1)
    {
        if(n%2!=0)
            return false;
        n=n/2;
    }
    return true;
}

bool isPowerOfTwoEfficient(int n)
{
    if(n==0)
        return false;
    return ((n&(n-1))==0);
}
int main()
{
    int n=8;
    cout<<isPowerOfTwo(n);
    cout<<isPowerOfTwoEfficient(n);

    return 0;
}