//Given an integer x, return true if x is a palindrome, and false otherwise.
//https://leetcode.com/problems/palindrome-number/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {

//Using String convert

//     string num=to_string(x);

//     int beg=0;
//     int end=num.size()-1;
//     while(beg<end)
//     {
//         if(num[beg]!=num[end])
//         {
//             return false;
//         }
//         else
//         {
//             beg++;
//             end--;

//         }
//     }

// return true;


    if (x < 0) 
    {
        return false;
    }

    long long reversed = 0;
    long long temp = x;

    while (temp != 0) 
    {
        int digit = temp % 10;
        cout<<"Digit:"<<digit;

        reversed = reversed * 10 + digit;
        cout<<"  Reversed: "<<reversed;
        
        temp /= 10;
        cout<<"  Temp:"<<temp<<'\n';
    }

    return (reversed == x);
    
}

int main()
{
    int number=121;
    cout<<isPalindrome(number);
    return 0;

}
