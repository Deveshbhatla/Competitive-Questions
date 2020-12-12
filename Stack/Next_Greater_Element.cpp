// Description : Given an array, print the Next Greater Element (NGE) for every element.
// The Next greater Element for an element x is the first greater element on the right side of x in array.
// Elements for which no greater element exist, consider next greater element as -1.
// Input : [13, 7, 6, 12]
//        Output
//  Element       NGE
//    13   -->     -1
//    7    -->     12
//    6    -->     12
//    12   -->     -1
//Time Complexity : O(n) Space: O(n)
#include<bits/stdc++.h>
using namespace std;
void printNGE(int arr[], int n) 
{
    stack < int > s;
    s.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        if (s.empty()) 
        {
            s.push(arr[i]);
            continue;
        }
        while(s.empty()==false && s.top() < arr[i])                  
        {
            cout<<s.top() << "-->"<< arr[i]<<'\n';  
            s.pop();
        }
        s.push(arr[i]);
    }
        while (s.empty() == false) 
        {
            cout<<s.top() << "-->" << -1 <<'\n';
            s.pop();
        }
    
}
int main()
{ 
    int arr[] = {11, 13, 21, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printNGE(arr, n); 
    return 0; 
}