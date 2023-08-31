// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
//https://leetcode.com/problems/3sum/?envType=study-plan-v2&envId=top-interview-150

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
            int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) 
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) 
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } 

                else if (sum < target) 
                {
                    j++;
                } 
                else 
                {
                    k--;
                }
            }
        }
        for(auto i : s)
            output.push_back(i);
        return output;

}

int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};

    for (int i = 0; i < threeSum(height).size(); i++)
    {
        for (int j = 0; j < threeSum(height)[i].size(); j++)
        {
            cout << threeSum(height)[i][j] << " ";
        }    
        cout << endl;
    }
    for (int i = 0; i < threeSum(height).size(); i++) 
    {
        for (int j = 0; j < threeSum(height)[i].size(); j++)
        {
            cout << threeSum(height)[i][j] << " ";
        }    
        cout << endl;
    }
    return 0;
}