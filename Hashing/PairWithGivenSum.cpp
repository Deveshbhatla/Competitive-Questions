//check if the given sum can be formed by pair of elements in the array
#include <bits/stdc++.h>
using namespace std;
int *pairWithGivenSum(int arr[], int m, int target)
{
    unordered_set<int> unorderedSet;
    static int result[2];
    for (int i = 0; i < m; i++)
    {
        if (unorderedSet.find(target - arr[i]) != unorderedSet.end()) // searhc for target - arr[i] in hash tabble
        {
            result[0] = arr[i];
            result[1] = target - arr[i];
            return result;
        }
        else
            unorderedSet.insert(arr[i]); //if the current element does not matches target sum insert into hash table
    }
    return 0;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int m = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    cout << *pairWithGivenSum(arr, m, target);
    cout << *(pairWithGivenSum(arr, m, target) + 1);
    return 0;
}