#include <bits/stdc++.h>
using namespace std;

//O(n) space and time
bool isPalindromeNaive(string &str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    if (str == rev)
        return true;
    else
        return false;
}

//O(n)time O(1) space
bool isPalindromeEfficient(string &str)
{
    int begin = 0, end = str.length() - 1;
    while (begin < end)
    {
        if (str[begin] != str[end])
            return false;
        begin++;
        end--;
    }
    return true;
}
int main()
{
    string str = "abba";
    cout << isPalindromeNaive(str);

    cout << isPalindromeEfficient(str);
    return 0;
}