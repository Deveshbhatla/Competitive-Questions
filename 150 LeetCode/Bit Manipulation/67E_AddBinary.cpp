// Given two binary strings a and b, return their sum as a binary string.

// Example:

// Input: a = "11", b = "1"
// Output: "100"

// https://leetcode.com/problems/add-binary/

#include <bits/stdc++.h>
using namespace std;
string addBinary(string a, string b)
{

    string result;

    int carry = 0;
    int i = a.length() - 1; // starting from right end
    int j = b.length() - 1; // starting from right end

    // continue till all the digits are processed and no carry is left
    while (i >= 0 || j >= 0 || carry == 1)
    {
        int sum = carry;

        if (i >= 0) 
            sum += a[i--] - '0';//subtract by '0' to convert the numbers from a char type into an int

        if (j >= 0) 
            sum += b[j--] - '0';//subtract by '0' to convert the numbers from a char type into an int

        // is sum is 2 then carry will be 1
        carry = sum > 1 ? 1 : 0;
			// if sum is 0 res is 1 & then carry would be 0;
            // if sum is 1 res is 1 & carry would be 0
            // if sum is 2 res is 0 & carry would be 1
            // if sum is 3 res is 1 & carry would be 1

        result += to_string(sum % 2);//moduling the sum to get the remainder
    }

    if (carry)
        result += to_string(carry);//add carry to res as long as it is not 0

    reverse(begin(result), end(result));//reverse the answer as we started from the end
    return result;
}

int main()
{
    string a="111";
    string b="11";
    cout<<addBinary(a,b);
    return 0;
}