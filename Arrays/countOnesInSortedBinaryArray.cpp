#include<bits/stdc++.h>
using namespace std;
int countOnesInSorted(int arr[], int n) //(n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count=n-i;
            break;
        }
    }
    return count;
} 
int countOnesEfficient(int arr[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(arr[mid] == 0)
			low = mid + 1;
		else
		{
			if(mid == 0 || arr[mid - 1] == 0)
				return (n - mid);
			else 
				high = mid -1;
		}
	}
	return 0;		
}
int main()
{
    int arr[]={0,0,0,0,0,1,1,1,1,1}, n=10;
    cout<<countOnesInSorted(arr,n);
    cout<<countOnesEfficient(arr,n);
    return 0;
}