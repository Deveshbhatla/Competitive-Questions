/*               ___
                |___|
 ___            |___|
|___|        ___|___|
|___|    ___|___|___|
|___|___|___|___|___|
*/
#include<bits/stdc++.h>
using namespace std;
int getWaterNaive(int arr[], int n)//O(n2)
{
	int result = 0;
	for(int i = 1; i < n - 1; i++)
	{
		int leftMax = arr[i];

		for(int j = 0; j < i; j++)
			leftMax = max(leftMax, arr[j]);

		int rightMax = arr[i];

		for(int j = i + 1; j < n; j++)
			rightMax = max(rightMax, arr[j]);

		result = result + (min(leftMax, rightMax) - arr[i]);
	}
	return result;
}

int getWaterEfficient(int arr[], int n)//O(n)
{
	int result = 0, leftMax[n], rightMax[n];

    leftMax[0] = arr[0];
    for(int i = 1; i < n; i++)
        leftMax[i] = max(arr[i], leftMax[i - 1]);


    rightMax[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
        rightMax[i] = max(arr[i], rightMax[i + 1]);

    for(int i = 1; i < n - 1; i++)
        result = result + (min(leftMax[i], rightMax[i]) - arr[i]);
    
    return result;
}

int main()
{
    int arr[]={3,0,1,2,5},n=5;
    cout<<getWaterNaive(arr,n)<<"   ";
    cout<<getWaterEfficient(arr,n);

}