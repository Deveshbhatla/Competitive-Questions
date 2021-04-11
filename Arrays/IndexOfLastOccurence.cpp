//Given a sorted array with repetition and an element x, we need to find index of last occurrence of x.
#include <bits/stdc++.h>
using namespace std;

int lastOccurence(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x > arr[mid]) //reverse binary search
            low = mid + 1;
        else if (x < arr[mid])
            high = mid - 1;
        else
        {
            if (mid != n - 1 || arr[mid + 1] != arr[mid])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5,5,5,5,5,8,5,4,3,2,2},n=15,x=5;
    cout<<"Found at: "<<lastOccurence(arr,n,x);
    return 0;
}