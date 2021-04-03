//Length of longest subarray with alternating even and odd elements

#include <bits/stdc++.h>
using namespace std;

int maxEvenOddNaive(int arr[], int n) //O(n2)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        int current = 1;

        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
                current++;
            else
                break;
        }

        result = max(result, current);
    }
    return result;
}

int maxEvenOddEfficient(int arr[], int n) //O(n)
{
    int result = 1, current = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            current++;

            result = max(result, current);
        }
        else
            current = 1;
    }
    return result;
}

int main()
{

    int arr[] = {5, 10, 20, 6, 3, 8}, n = 6; //6 3 8 length =3
    cout << maxEvenOddNaive(arr, n) << "   ";
    cout << maxEvenOddEfficient(arr, n);
    return 0;
}