#include <bits/stdc++.h>
using namespace std;

    int majorityElement(vector<int>& nums) {

        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
        }
        for(auto i: map)
        {
            if(i.second>nums.size()/2)
            return i.first;
        }
        return 0;
        
    }

    int main()
{
    vector<int> nums = {1,0,1,1,1,2,2,3,1,1};
    cout<<majorityElement(nums);
    return 0;
}