#include <deque>
#include <iostream>

using namespace std;

void printKMax(int arr[], int n, int k)
{
 
    std::deque<int> Qi(k);
  
    int i;
    for (i = 0; i < k; ++i) 
    {
        // For every element, the previous smaller elements are useless so remove them from Qi
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back(); // Remove from rear

        // Add new element at rear of queue
        Qi.push_back(i);
    }

    // Process rest of the elements,from arr[k] to arr[n-1]
    for (int i=k; i < n; ++i) 
    {
        // The element at the front of the queue is the largest element of previous window
        cout << arr[Qi.front()] << " ";

        // Remove the elements which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front(); 

        // Remove all elements smaller than the currently being added element 
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

      
        Qi.push_back(i);
    }

    // Print the maximum element of last window
    cout << arr[Qi.front()];
}

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printKMax(arr, n, k);

    return 0;
}
