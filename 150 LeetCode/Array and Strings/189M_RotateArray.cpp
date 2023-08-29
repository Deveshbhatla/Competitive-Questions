#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
        
        vector<int> temp;
       int  n=nums.size();
        k%=n;

        for(int i=nums.size()-k;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-k;i++)
        {
            temp.push_back(nums[i]);
        }
        nums.clear();

        for(int i=0;i<temp.size();i++)
            nums.push_back(temp[i]);

     for(int i=0;i<temp.size();i++)
            cout<<temp[i];
            cout<<endl;

            
            //Without using temp array    
        for (int i = 0; i < (n-k)/2; i++)
        {
            swap(nums[i], nums[n-k-1-i]);
        }
        
        for (int i = 0; i < k/2; i++)
        {
            swap(nums[n-k+i], nums[n-i-1]);
        }

        for (int i = 0; i < n/2; i++)
        {
            swap(nums[i], nums[n-i-1]);
        }
        

        
        for(int i=0;i<temp.size();i++)
            cout<<temp[i];
    }
        int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums,3);
    return 0;
}