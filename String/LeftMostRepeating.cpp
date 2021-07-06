//Find the first occurence of leftmost repeating element. eg abbacc //OP:0(ie a, index of first repeating element)
#include <bits/stdc++.h>
using namespace std;
//O(n2)
int LeftMostRepeatingNaive(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
                return i;
        }
    }
    return -1;
}
const int CHAR = 256;
//O(n)
int LeftMostRepeatingEfficient(string &str)
{
    int count[CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i]] > 1)
            return i;
    }
    return -1;
}


int LeftMostRepeatingMoreEfficient(string &str)
{
    bool visited[CHAR];
    fill(visited, visited + CHAR, false);//filling the visited array with -1(false)
    int res = -1;
    for (int i = str.length() - 1; i >= 0; i--)//traverse string from right to left
    {
        if (visited[str[i]])//if already visited then copy the value of that index into result
            res = i;
        else
            visited[str[i]] = true;
    }

    return res;
}

int main()
{
    string str = "abbacc";
    cout << LeftMostRepeatingNaive(str);
    cout << LeftMostRepeatingEfficient(str);
    cout << LeftMostRepeatingMoreEfficient(str);

    return 0;
}