#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++)
    {
        int count =1;
        if(arr[i]!=-1)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                    arr[j]=-1;

                }    
            }
        }
        if(count>1)
        {       
            cout<<arr[i]<<" "<<count;
        }
    }

     for (int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
    return 0;
}
