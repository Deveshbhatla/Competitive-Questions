
#include <bits/stdc++.h>
using namespace std;

void leftrotate(string &str1, int d)
{
    reverse(str1.begin(), str1.begin() + d);
    reverse(str1.begin() + d, str1.end());
    reverse(str1.begin(), str1.end());
}

void rightrotate(string &str2, int d)
{
    leftrotate(str2, str2.length() - d);
}

int main()
{
    string str1 = "abcde";
    leftrotate(str1, 2);
    cout << str1 << '\n';

    string str2 = "abcde";
    rightrotate(str2, 2);
    cout << str2 << '\n';

    return 0;
}
