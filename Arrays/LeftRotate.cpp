//Anticlockwise
#include<bits/stdc++.h>
using namespace std;

 void leftRotateOne(int arr[], int n)
{
	int temp = arr[0];
	for(int i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}
	arr[n - 1] = temp;
}
void leftRotateNaive(int arr[],int n, int d)// Time: O(nd), space:O(1)
{
    for(int i=0;i<d;i++)
    {
        leftRotateOne(arr,n);
    }
}
void leftRotate(int arr[],int n, int d)//Time: O(n+d)or O(n), space: O(d)
{
    int temp[d];
    for(int i=0;i<d;i++)//adding the elements to a temp array 
        temp[i]=arr[i];

    for(int i=d;i<n;i++)//shifting every element d positions bsck
        arr[i-d]=arr[i];

    for(int i=0;i<d;i++)//copying the remaing elements to the back of the array
        arr[n-d+i]=temp[i];        
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
void leftRotateSpaceEfficient(int arr[],int n,int d)// Time: O(n), Space:O(1)
{
    reverse(arr,0,d-1);//reversing the first d elements
    reverse(arr,d,n-1);//reversing the remaining elements
    reverse(arr,0,n-1);//reversing the whole array
}
void leftRotateTrick(int arr[],int n, int d)
{
    for(int i=0;i<n;i++)
        cout<<arr[(i+d)%n]<<" ";
}    
int main()
{
	
      int arr[] = {1, 2, 3, 4, 5}, n = 5;

      cout<<"Before Rotation"<<endl;
       for(int i = 0; i < n; i++)
       		cout<<arr[i]<<" ";
       cout<<'\n';
       leftRotateTrick(arr,n,3);
       leftRotateSpaceEfficient(arr, n, 3);
       cout<<"After Rotation"<<endl;
       for(int i = 0; i < n; i++)
       		cout<<arr[i]<<" ";
    
}
