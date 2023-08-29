#include<bits/stdc++.h>
using namespace std;
    
vector<int> twoSum(vector<int>& numbers, int target) {
        
int n=numbers.size();
        for(int i=0, j=n-1; i<j; )
        {
            int sum=numbers[i]+numbers[j];
            if (sum == target) 
                return {i+1, j+1};
            else if ( sum< target) 
                i++;
            else 
                j--;
        }
        return {};        

    }

int main()
{
    vector<int> numbers={2,7,3};
    int target=9;
    for(auto x : twoSum(numbers,target))
    {
        cout<<x;
    }
    return 0;
}