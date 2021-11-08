#include<bits/stdc++.h>
using namespace std;

int lcsNaive(string s1, string s2, int m, int n)
{
    if(m==0||n==0)
        return 0;

    if(s1[m-1]==s2[n-1])
        return 1+lcsNaive(s1,s2,m-1,n-1);
    else
        return max(lcsNaive(s1,s2,m-1,n),lcsNaive(s1,s2,m,n-1));    
}

//Memoization
int memo[1000][1000];
int lcsMemoization(string s1, string s2, int m, int n)//O(mn)
{
    if(memo[m][n]!=-1)
        return memo[m][n];
        
    if(m==0 || n==0)
        memo[m][n]=0;
        
    else
    {
        if(s1[m-1]==s2[n-1])
            memo[m][n] = 1 + lcsMemoization(s1,s2,m-1,n-1);
        else
            memo[m][n] = max(lcsMemoization(s1,s2,m-1,n),lcsMemoization(s1,s2,m,n-1));
    }
    
    return memo[m][n];
    
}

//Tabulation
int lcsTabulation(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];

    //assigning the first row and columns as 0
    for(int i=0;i<m;i++)
        dp[i][0]=0;

    for(int j=0;j<n;j++)
        dp[0][j]=0;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[m][n];    
}
int main()
{

    memset(memo,-1,sizeof(memo));
    
	string s1="AXYZ", s2="BAZ";
    int m=4,n=3;
    cout<<lcsTabulation(s1,s2,m,n);
    return 0;
}