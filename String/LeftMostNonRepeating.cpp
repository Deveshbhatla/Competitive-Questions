//Return the index of leftmost element that occurs only once
#include <bits/stdc++.h>
using namespace std;
int LeftMostNonRepeatingNaive(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        bool flag = false;
        for (int j = 0; j < str.length(); j++)
        {
            if (i != j && str[i] == str[j]) //if repeating then set the flag to true and come out of the loop
            {
                flag = true;
                break;
            }
        }
        if (!flag) //if flag remains false then we didn't find any repeating string
            return i;
    }
    return -1;
}
const int CHAR = 256;
//O(n)
int LeftMostNonRepeatingEfficient(string &str)
{
    int count[CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i]] == 1)
            return i;
    }
    return -1;
}
int LeftMostNonRepeatingMoreEfficient(string &str)
{
    int firstInstance[CHAR];
    fill(firstInstance, firstInstance + CHAR, -1);

    for (int i = 0; i < str.length(); i++)
    {
        if (firstInstance[str[i]] == -1)
            firstInstance[str[i]] = i;//first time appeared
        else
            firstInstance[str[i]] = -2;//appeared and repeated
    }
    int res = INT_MAX;
    for (int i = 0; i < CHAR; i++)
    {
        if (firstInstance[i] >= 0)
            res = min(res, firstInstance[i]);
    }
    return (res == INT_MAX) ? -1 : res;
}
int main()
{
    string str = "abbcbda";
    cout << LeftMostNonRepeatingNaive(str);
    cout << LeftMostNonRepeatingEfficient(str);
    cout << LeftMostNonRepeatingMoreEfficient(str);

    return 0;
}