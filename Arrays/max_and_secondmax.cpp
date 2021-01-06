#include <bits/stdc++.h>
using namespace std;
vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN, max2= INT_MIN;
    
     vector<int> v;
     
     sort(arr,arr+sizeOfArray);
          v.push_back(arr[sizeOfArray-1]);

     for(int i=sizeOfArray-2;i>=0;i--)
     {
         if(arr[i]!=arr[sizeOfArray-1])
          {  v.push_back(arr[i]);
          return v;
          }
          
          
     }
       v.push_back(-1);

     return v;
}
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    vector<int> ans = largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	
	return 0;
}