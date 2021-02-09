/*
Input: a[] = {2, 1, 5, 4, 8, 3, 6, 7};
       b[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}
Output: B A F D C G H E
Explanation:
Consider first elements of both arrays: (2, A)
Since the correct location of element 2 in a[] is at position 2.
Therefore, the corresponding element of b[] is also placed at position 2.
Similarly, the rest of the elements are arranged in the following way:
(1, B) 
(2, A) 
(3, F) 
(4, D) 
(5, C) 
(6, G) 
(7, H) 
(8, E) 
*/

#include<bits/stdc++.h>
using namespace std;

void pairSort(int a[], char b[], int n)
{   
    pair<int, int> arr_p[n];
    
    // Fill the array of pairs such that 
    // first element of pair is the elements of a[]
    // second element of pair is the corresponding
    // element of array b[]
    for(int i = 0; i < n; i++)
    {
        arr_p[i].first = a[i];
        arr_p[i].second = b[i];
    }
    
    // Sort the array of pairs By default, the sort function sorts a  container by first element
    sort(arr_p, arr_p + n);
    
    for(int i = 0; i < n; i++)
    {
        b[i] = arr_p[i].second;
    }
    
    // Print the elements of pairs
    for(int i = 0; i < n; i++)
    {
        cout<<"("<<arr_p[i].first <<", "<<b[i]<<") ";
    }

}

int main()
{   
    
    int a[] = {2, 1, 5, 4, 8, 3, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    char b[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    pairSort(a, b, n);
    return 0;
}
