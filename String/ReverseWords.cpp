//Eg: Input: Hello there
// output:there Hello
#include<bits/stdc++.h>
using namespace std;
void reverse(char str[],int low, int high){
    while(low<=high){
        swap(str[low],str[high]);
        low++;
        high--;
    }
}

void ReverseWords(char str[], int n)
{
    int start =0;
    for(int end=0;end<n;end++)
    {
        if(str[end]==' ')
        {
            reverse(str,start,end-1);
            start=end+1;

        }
    }
     reverse(str,start,n-1);
    reverse(str,0,n-1);
}
int main() 
{ 
    string s = "Hello there";
    int n=s.length();
    char str[n];
    strcpy(str, s.c_str());
    ReverseWords(str,n);
    for (int i = 0; i < n; i++) 
        cout << str[i];
    
    return 0; 
} 