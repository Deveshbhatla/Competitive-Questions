#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
    if(n==0)
     return;
    //cout<<n<<" "; If cout here instead of below it will print n to 1
    print(n-1);
        cout<<n<<" ";

}
int main()
{
    print(3);
    return 0;
}
