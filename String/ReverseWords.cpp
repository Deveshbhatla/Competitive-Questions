//Eg: Input: Hello there
// output:there Hello
#include<bits/stdc++.h>
using namespace std;
 void reverse(string &str,int low, int high){
    int n = high - low;

    for (int i = 0; i < n / 2; i++) {
        swap(str[i + low], str[n - i - 1 + low]);
    }
}

    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int start =0;
    for(int end=0;end<S.length();end++)
    {
        if(S[end]==' ')
        {
            reverse(S,start,end);
            start=end+1;

        }
    }
reverse(S,start,S.length());
reverse(S,0,S.length());
return S;

    } 
int main() 
{ 
    string s = "Hello there";
    int n=s.length();
    char str[n];

    strcpy(str, s.c_str());

    cout<<reverseWords(s);
    
    return 0; 
} 