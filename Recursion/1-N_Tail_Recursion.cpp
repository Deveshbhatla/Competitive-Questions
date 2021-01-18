#include<bits/stdc++.h>
using namespace std;
//k is the initial number, it will print n next numbers from k
void fun(int n, int k)
{
    if(n==0)
     return ;
    cout<<k<<" ";
    return fun(n-1,k+1);
    
}
int main()
{
    fun(3,2);
    return 0;
}