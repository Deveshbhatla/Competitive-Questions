//Given an integer array nums where every element appears three times except for one, 
//which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.

//https://leetcode.com/problems/single-number-ii/



#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    //using extra space
    // unordered_map<int, int> m;

    // for (auto x : nums)
    //     m[x]++;

    // for (auto x : m)
    // {
    //     if (x.second == 1)
    //         return x.first;
    // }
    // return 0;

    //constant space
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
;
}

int main()
{
    vector<int> nums{0,1,0,1,0,1,99};
    cout << singleNumber(nums);
    return 0;
}
