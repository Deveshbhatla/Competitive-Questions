// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> set;
    //inserting all the numbers into set
    for (int num : nums)
    {
        set.insert(num);
    }

    int longestConsecutiveSequence = 0;

    for (int num : nums)
    {
        if (set.find(num - 1) == set.end())//if not till end
        {
            int currentNumber = num;
            int currentConsecutiveSequence = 1;
            while (set.find(currentNumber + 1) != set.end())
            {
                currentNumber++;
                currentConsecutiveSequence++;
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
        }
    }
    return longestConsecutiveSequence;
}

int main()
{
    vector<int> nums{100, 4, 200, 1, 3, 2};

    cout << longestConsecutive(nums);

    return 0;
}