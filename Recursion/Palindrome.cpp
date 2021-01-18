#include <bits/stdc++.h>
using namespace std;
bool Palindrome(string str, int start, int end)
{
	if(start >= end)
		return true;

	return ((str[start]==str[end]) && Palindrome(str, start + 1, end - 1));
}

int main() {
	
	string s = "eye";
	cout<<Palindrome(s, 0, s.length() -1) ? "true" : "false";
	return 0;
}