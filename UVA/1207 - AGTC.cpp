#include<bits/stdc++.h>
using namespace std;

#define MX 1005
char str1[MX],str2[MX];
int dp[MX][MX];

int solve(int i,int j)
{
    if(i==0)    return  j;
    else if(j==0)   return  i;
    else if(dp[i][j]!=-1)   return  dp[i][j];
    int res=0;
    if(str1[i-1]==str2[j-1])  res = solve(i-1,j-1);
    else    res = 1+min(solve(i-1,j),min(solve(i,j-1),solve(i-1,j-1)));
    return  dp[i][j] = res;
}

int main()
{
    int n,m;
    while(scanf("%d %s %d %s",&n,str1,&m,str2)==4)
    {
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(n,m));
    }
    return  0;
}
