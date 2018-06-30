#include<bits/stdc++.h>
using namespace std;

#define MX 1005
char str[MX];
int dp[MX][MX];

int solve(int i,int j)
{
    if(i>j) return  0;
    else if(dp[i][j]!=-1)   return  dp[i][j];
    int res=0;
    if(str[i]==str[j])  res = 1+(i!=j)+solve(i+1,j-1);
    else    res = max(solve(i+1,j),solve(i,j-1));
    return  dp[i][j] = res;
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(str);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,strlen(str)-1));
    }
    return  0;
}

/// empty string is also a Palindrome.
