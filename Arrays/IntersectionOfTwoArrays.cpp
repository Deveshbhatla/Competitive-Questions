//To find the common elements between the two sorted arrays
#include <iostream>
#include <algorithm>
using namespace std;

void intersectionNaive(int a[], int b[], int m, int n)//O(mn)
{
    
    for(int i=0;i<m;i++)
    {
        if(i>0 && a[i-1]==a[i])//should not print duplicates twice
            continue;
        for(int j=0;j<n;j++)
            if(a[i]==b[j]){
                cout<<a[i]<<" ";
                break;
            }
    }    
}

void IntersectionEfficient(int a[],int b[],int m,int n)//O(m+n)
{
 int i=0,j=0;
    while(i<m && j<n)
    {
        if(i>0 && a[i-1]==a[i])
        {
            i++;
            continue;
        }
        if(a[i]<b[j])
        {
            i++;
        }
        else if(a[i]>b[j])
        {
            j++;
        }
        else
        {
            cout<<a[i]<<" ";
            i++;j++;
        }
    }    
}

int main() 
{	
    int a[]={3,5,10,10,10,15,15,20};
    int b[]={5,10,10,15,30};
	
	int m=sizeof(a)/sizeof(a[0]);
	int n=sizeof(b)/sizeof(b[0]);
	intersectionNaive(a,b,m,n);
    IntersectionEfficient(a,b,m,n);
}