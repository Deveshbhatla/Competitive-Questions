#include<bits/stdc++.h>
using namespace std;
int countOccurences(int arr[],int n,int x)//O(Logn)
{
    //Get First occurence of x
    int *low = lower_bound(arr, arr + n, x);

    if (low == (arr + n) || *low != x)
        return 0;

    //Get the index of last occurrence of x
    int *high = upper_bound(low, arr + n, x);

    return high - low;
}
int main()
{
    int arr[]={1,2,3,3,4,5,5},n=7,x=5;
    cout << "Occurrence of " << x << " is: " << countOccurences(arr, n, x);
    return 0;
}