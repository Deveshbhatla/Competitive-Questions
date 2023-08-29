//Remove Duplicates , only 2 duplicates are allowed per number
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {

        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(index<2||nums[i]>nums[index-2])
            {
                nums[index++]=nums[i];
            }
        }
        return index;
        
    
    }
    int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int val = 3;

    cout<<removeDuplicates(nums);
    return 0;
}