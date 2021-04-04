//Given a binary array. Make all elements same. Either flip all zeroes or all ones.
#include <bits/stdc++.h>
using namespace std;
void minimumConsecutiveFlips(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
                cout << "Flip From " << i << " to ";
            else
                cout << i - 1 << '\n';
        }
    }

    if (arr[n - 1] != arr[0])//if last element is not equal to the first element
        cout << n - 1 << '\n';
}

int main()
{
    int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0}, n = 9;
    minimumConsecutiveFlips(arr, n);
    return 0;
}