#include <bits/stdc++.h>
using namespace std;

void sortArr(int arr[], int n)
{

    vector<pair<int, int> > vp;

    for (int i = 0; i < n; ++i)
    {
        vp.push_back(make_pair(arr[i], i));
    }

    sort(vp.begin(), vp.end());

    cout << "Element\t index" << endl;
    for (int i = 0; i < vp.size(); i++) 
    {
        cout << vp[i].first << "\t"<< vp[i].second << endl;
    }
}

int main()
{
    int arr[] = { 2, 5, 3, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortArr(arr, n);

    return 0;
}
