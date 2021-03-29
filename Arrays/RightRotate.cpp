//Clockwise
#include<bits/stdc++.h>
using namespace std;
void rightRotateByOne(int arr[],int n)
{
   int temp = arr[n-1];
	for(int i = n-2; i >= 0; i--)//if you start from 0 or 1, it will overwrite all the next values with previous values. eg 5 1 1 1 1
	{
		arr[i+1] = arr[i];
	}
	arr[0] = temp;
}
void rightRotateNaive(int arr[],int n,int d)
{
    for(int i=0;i<d;i++)
    {
        rightRotateByOne(arr,n);
    }
}
//Auxilary function for reversing of the array
void reverse(int arr[],int low,int high)
{
    while(low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
void rightRotateSpaceEfficient(int arr[],int n,int d)// Time: O(n), Space:O(d)
{
    reverse(arr, 0, n-1);//reversing the wholearray
	reverse(arr, 0, d-1);//reversing the first d elements
	reverse(arr, d, n-1);//reversing the remaining elements
}
int main()
{
    int arr[]={1,2,3,4,5},n=5;
    cout<<"Before Rotation"<<endl;
       for(int i = 0; i < n; i++)
       		cout<<arr[i]<<" ";
       cout<<'\n';
    rightRotateSpaceEfficient(arr,n,3);
     cout<<"After Rotation"<<endl;
       for(int i = 0; i < n; i++)
       		cout<<arr[i]<<" ";
    return 0;
}