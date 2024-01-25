// You are given an integer array nums. You are initially positioned at the array's first index,
// and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// https://leetcode.com/problems/jump-game/description/


//Greedy solution 
//Time Complexity:O(n), space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int maximumReach = 0;
    int n = nums.size();

    // if the first element itself is greater than the last one, then we can return true without going into the loop
    if (nums[0] >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        // current jump distance as the array element
        int currentJumpDistance = nums[i];

        // if the maximum reach is less than i, then return false, as we cannot jump till the end of the array
        //it is because i is the position of the elements, if maximum reach becomes less than i, then we can only jump till 
        //i-(something), hence, we cannot jump till i, so return false 
        if (maximumReach < i)
            return false;

        // calculate the maximum reach by taking the max of itself and the current i and the jump distance
        maximumReach = max(maximumReach, i + currentJumpDistance);

        // again, if the maximum reach is bigger than n, no need to continue the loop again
        if (maximumReach >= n)
            return true;
    }
    return true;
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4}; // false
    string result = canJump(nums) ? "true" : "false";

    cout << result;
    return 0;
}