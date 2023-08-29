//Input: s = "A man, a plan, a canal: Panama"
//Output: true
//Explanation: "amanaplanacanalpanama" is a palindrome.
#include<bits/stdc++.h>
using namespace std;

bool isValidPalindrome(string s) {

//TwoPointer
    int start=0;
    int end=s.size()-1;

    while(start<=end)//To iterate
    {

        if(!isalnum(s[start]))//If any character is not alphanumeric,skip it and proceed with the next iteration of the while loop
        {
            start++;
            continue;
        }

        if(!isalnum(s[end]))//If any character is not alphanumeric,skip it and proceed with the next iteration of the while loop
        {
            end--;
            continue;
        }

        if(tolower(s[start])!=tolower(s[end]))//If characters does not match, return false
            return false;

        else
        {
            start++;
            end--;
        }

    }
    return true;

}
int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout<<isValidPalindrome(s);
    return 0;
}