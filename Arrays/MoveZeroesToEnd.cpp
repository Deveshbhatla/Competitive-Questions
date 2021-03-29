#include<bits/stdc++.h>
using namespace std;

void zerosToEndEfficient(int arr[], int n)
{
    int count = 0;  
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i]; 
                                   
    while (count < n)
        arr[count++] = 0;
}
int main()
{
    int arr[]={5,7,2,0,0,0,3,2,0,0,0}, n=11;
    zerosToEndEfficient(arr,n);
    cout<<"After Moving zeroes to the end"<<endl;
       for(int i = 0; i < n; i++)
       		cout<<arr[i]<<" ";

}