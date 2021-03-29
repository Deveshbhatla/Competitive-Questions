#include<bits/stdc++.h>
using namespace std;
void Leaders(int arr[],int n)//O(n2)
{
   for(int i = 0; i < n; i++)
	{
		bool flag = false;
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j]>=arr[i])
			{
				flag = true;
				break;
			}
		}
		if(flag == false)
			cout<<arr[i]<<" ";
	}
}
void leaderEfficient(int arr[],int n)//O(n2) but prints the leader in reverse order
{
    int currentLeader = arr[n - 1];
	cout<<currentLeader<<" ";
	for(int i = n - 2; i >= 0; i--)
	{
		if(arr[i]>currentLeader)
		{
			currentLeader = arr[i];
			cout<<currentLeader<<" ";
		}
	}
}

int main()
{
    int arr[]={7, 10, 4, 10, 6, 5, 2},n=7;
    leaderEfficient(arr,n);
    return 0;
}