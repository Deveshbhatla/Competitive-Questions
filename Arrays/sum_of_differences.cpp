// You are given an array arr of n integers. You need to find the sum of the absolute differences of the largest element and the smallest element, 
//then second largest element and the second smallest element and so on.
// If n is odd then also include the middle element in the sum.


#include <bits/stdc++.h>
using namespace std;

int sumOfDiff(int arr[],int n)
{
int sum = 0; 
if(n==1)
{
    return arr[0];
}
sort(arr,arr+n);
// to handle duplicate elements
    // int temp[n]; 
  
    // // Start traversing elements 
    // int j = 0; 
    // for (int i=0; i<n-1; i++) 
  
    //     // If current element is not equal 
    //     // to next element then store that 
    //     // current element 
    //     {if (arr[i] != arr[i+1]) 
    //         temp[j++] = arr[i]; }
  
    // // Store the last element as whether 
    // // it is unique or repeated, it hasn't 
    // // stored previously 
    // temp[j++] = arr[n-1]; 
        
    // // Modify original array 
    // for (int i=0; i<j; i++) 
    //     arr[i] = temp[i];

    //n=j-1;
    
    if(n%2!=0)
    {
        for(int i=0;i<n/2;i++)
        {
         sum+= arr[n-1-i]-arr[i];
        }
        sum+=arr[n/2];    
        
    }
    else
        
     {    for(int i=0;i<n/2;i++)
        {
         
         sum+= arr[n-1-i]-arr[i];
        }
     }
    return sum; 
    
}
int main() 
{
	int arr[5]={1,2,3,4};  
	cout<<sumOfDiff(arr,4);

	return 0;
}  