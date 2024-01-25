// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words,
// if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// https://leetcode.com/problems/jump-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int totalJumps = 0;
    int n = nums.size();
    int currentIndex = 0;

    for (int i = 1; i < n; i++)
    {
        nums[i] = max(nums[i] + 1, nums[i - 1]);
    }

    while (currentIndex < n - 1)
    {
        totalJumps++;
        currentIndex = nums[currentIndex];
    }
    return totalJumps;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums);
    return 0;
}