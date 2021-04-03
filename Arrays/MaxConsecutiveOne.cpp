#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOneNaive(bool arr[],int n)//O(n2)
{
    int result=0;
    for(int i=0;i<n;i++)
    {
        int current_Result=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==1)
                current_Result++;
            else
                break;//i++
        }
        result=max(result,current_Result);
    }
    return result;
}
int maxConsecutiveOneEfficient(bool arr[],int n)//O(n)
{
    int result =0,current=0;
    for(int i=0;i<n;i++)
    {   
        if(arr[i]==0)//if you see a zero, reset the count
            current=0;
        else
        {
            current++;
            result=max(result,current);
        }
    }
    return result;
}
int main()
{
    bool arr[]={1,0,1,1,1,1,1,0,0,0,1};
    int n=11;
    cout<<maxConsecutiveOneNaive(arr,n)<<" ";
    cout<<maxConsecutiveOneEfficient(arr,n);
    return 0;   
}