// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

//https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right) 
    {
        int currentArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, currentArea);

        if (height[left] < height[right]) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }

    return maxArea;

}

    int main()
    {
        vector<int> height={1,8,6,2,5,4,8,3,7};
        cout<<maxArea(height);
        return 0;
    }