//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

//You must implement a solution with a linear runtime complexity and use only constant extra space.


#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
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
       int result=0;
	   for(auto x:nums)
	   result^=x;// xor operation. Element with even frequency will result in 0
	   return result;
}

int main()
{
    vector<int> nums{2, 2, 3, 3, 4, 4, 5};
    cout << singleNumber(nums);
    return 0;
}
