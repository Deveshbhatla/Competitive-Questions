//To remove one repeating element in unsorted array
#include <bits/stdc++.h>
using namespace std;
int checkRepeatNaive(int arr[], int n) //O(n) time,O(n) space
{
    bool visit[n];

    memset(visit, false, sizeof(visit)); //sets the value of the elements in an array

    for (int i = 0; i < n; i++)
    {
        if (visit[arr[i]])
            return arr[i];
        visit[arr[i]] = true;
    }

    return -1;
}

int checkRepeatEfficient(int arr[], int n) //O(n) time,O(1) space
{
    int slow = arr[0], fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while (slow != fast);

    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main()
{

   int arr[] = {1, 3, 2, 4, 6, 5, 7, 3}, n= 8;

    cout << checkRepeatNaive(arr, n)<<'\n';
    cout << checkRepeatEfficient(arr, n);

    return 0;
}