#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target) 
{
    vector<int> sum;
    const int size = nums.size();

    for(int i=0;i<size-1;++i)
    {
        for(int j=i+1;j<size;++j)
        {
            if(nums[j]+nums[i]==target)
            {
                sum.push_back(i);
                sum.push_back(j);
                return sum;      
            }
        }
    }
    return sum;
        
}
    
int main()
{
    
    vector<int> nums;
    for(int i=1;i<10;i++)
    nums.push_back(i);
    int target=17;

    for(auto x:twoSum(nums,target))
        cout<<x<<" ";

    //or it can be written as
    //vector<int> answer=twoSum(nums,target);

    // for(auto itr2 = answer.begin(); itr2!=answer.end();itr2++)
    //     cout<<*itr2<<" ";

    return 0;
}