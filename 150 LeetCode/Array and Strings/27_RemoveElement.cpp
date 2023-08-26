#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
        
}

int main()
{
    vector<int> nums = {3,3,2,5};
    int val = 3;

    cout<<removeElement(nums, val);
    return 0;
}