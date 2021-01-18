#include <bits/stdc++.h>
using namespace std;

int longestLength(int arr[],int n)
{
    int answer = 1,temp = 1; 
      for (int i = 1; i < n; i++)
      { 
  
        if (arr[i] == arr[i - 1]) 
        { 
            ++temp; 
        } 
        else 
        { 
            answer = max(answer, temp); 
            temp = 1; 
        } 
    } 
    answer = max(answer, temp); 
    return answer; 
    
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	   cout<<longestLength(arr,n)<<endl;
	}
	return 0;
} 