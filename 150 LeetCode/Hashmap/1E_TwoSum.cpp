// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numMap;//key=element in vector, value = element position
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];//Counting complement each iteration
        if (numMap.count(complement))//If map contains the complement, return address(aka map's value)
        {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;// Add the number as a key in map and value as i
    }

    return {}; // No solution found
}

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for (auto x : result)
        cout << x;
    return 0;
}