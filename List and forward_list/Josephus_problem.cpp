#include<bits/stdc++.h>
using namespace std;
int josephus(int n, int k) //O(nk), space O(n)
{
    list<int> l;
    for(int i=0;i<n;i++)
        l.push_back(i);
    auto it=l.begin();

    while(l.size()>1)// to stop the loop when there is one item left
    {
        for(int count=1;count<k;count++)
        {
            it++;

            if(it==l.end()) //to make sure that the list is in circular manner
                it=l.begin();
        }
        it=l.erase(it);

        if(it==l.end())
            it=l.begin();
    }
    return *l.begin(); //* to get the value

}

int main()
{
    int n=7,k=3;
    cout<<"Survivor is: "<<josephus(n,k);
    return 0;
}