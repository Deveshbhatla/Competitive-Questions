#include <bits/stdc++.h>
using namespace std;
//Space: O((N-M+1)*M) Time:O(1)
void NaivePatternSearching(string &text, string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= (n - m); i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (pattern[j] != text[i + j])
                break;

        if (j == m) //if the index of last element matches the size of the pattern then return the first index
            cout << i << " ";
    }
}

//Only for patterns with distinct letters
void ImprovedPAtternSearching(string &text, string &pattern)
{
    int m = pattern.length();
    int n = text.length();
    for (int i = 0; i <= (n - m);)
    {
        int j;
        for (j = 0; j < m; j++)
            if (pattern[j] != text[i + j])
                break;

        if (j == m)
            cout << i << " ";
        if (j == 0)
        {
            i++;
        }
        else
        {
            i = (i + j);
        }
    }
}
int main()
{
    string txt = "ABCABCD";
    string pat = "ABCD";
    NaivePatternSearching(txt, pat);
    ImprovedPAtternSearching(txt, pat);
}