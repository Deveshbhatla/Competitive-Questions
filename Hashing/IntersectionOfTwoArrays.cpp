//Count distinct common elementsif a{1,2,3} & b{2,3,4} output is :2{2,3}
#include <bits/stdc++.h>
using namespace std;
int intersection(int arr1[], int m, int arr2[], int n)
{
    unordered_set<int> unorderedSet;
    for (int i = 0; i < m; i++)

        unorderedSet.insert(arr1[i]);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (unorderedSet.find(arr2[i]) != unorderedSet.end())
        {
            result++;
            unorderedSet.erase(arr2[i]);
        }
    }

    return result;
}
int main()
{
    int arr1[] = {15, 17, 27, 27, 28, 15};
    int arr2[] = {16, 17, 28, 17, 31, 17};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout <<"number of distinct common elements: "<< intersection(arr1, m, arr2, n);
    return 0;
}