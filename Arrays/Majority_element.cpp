#include <bits/stdc++.h>
using namespace std;
//if majority element exists
int majorityElement(vector<int>& nums) 
{
    sort(nums.begin(), nums.end()); 
    return nums[nums.size()/2];
}
int majorityElement(int a[], int size)
{
  int count = 0;
        int candidate =0;

        for (int i=0;i<size;i++)
        {
            if (count == 0) 
            {
                candidate = a[i];
            }
            count += (a[i] == candidate) ? 1 : -1;
        }

        return candidate;

}
int main() 
{
    int a[10]={1,2,2,2,2,2,5,3,4,};
    cout<<majorityElement(a,9);
    vector<int> v={2,3,2};
//cout<<majorityElement(v);
return 0;
}