// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.
//https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150
    
#include<bits/stdc++.h>
using namespace std;

    vector<int> plusOne(vector<int>& digits) {


//     for(int i=digits.size()-1;i>=0;i--)
//     {
//         if(i == digits.size()-1)
//         digits[i]++;

//         if(digits[i]==10)
//         {
//             digits[i]=0;
        
//             if(i != 0)
//                 digits[i-1]++;
    
//             else
//             {
//                  digits.push_back(0);
//                  digits[i]=1;
//             } 
//         }          
//     }

//  return digits;


        for(int i=digits.size()-1;i>=0;i--){
            
           if(digits[i] != 9){
                digits[i]++;
                return digits;
            }else{
                 digits[i] = 0;
           }
       }
       digits.insert(digits.begin(),1);
       return digits;
    }


int main()
{
    vector<int> nums = {1,2,3,9};
    for(auto x:plusOne(nums))
    cout<<x<<" ";

    return 0;

}