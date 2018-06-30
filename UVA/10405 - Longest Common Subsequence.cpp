#include<bits/stdc++.h>
using namespace std;

#define MX 1005
string str1,str2;
int dp[MX][MX];

int solve(int i,int j)
{
    if(i>=str1.size() || j>=str2.size())    return  0;
    else if(dp[i][j]!=-1)   return  dp[i][j];
    int res=0;
    if(str1[i]==str2[j])    res = 1+solve(i+1,j+1);
    else    res = max(solve(i+1,j),solve(i,j+1));
    dp[i][j] = res;
    return  dp[i][j];
}

int main()
{
    while(1)
    {
        if(!getline(cin,str1))  return  0;
        if(!getline(cin,str2))  return  0;
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,0));
    }
    return  0;
}

/// Same solution

#include<bits/stdc++.h>
using namespace std;

#define MX 1005
string str1,str2;
int dp[MX][MX];

int solve(int i,int j)
{
    if(i>=str1.size() || j>=str2.size())    return  0;
    else if(dp[i][j]!=-1)   return  dp[i][j];
    int res=0;
    res = max(solve(i+1,j),solve(i,j+1));
    if(str1[i]==str2[j])    res = max(res,1+solve(i+1,j+1));
    dp[i][j] = res;
    return  dp[i][j];
}

int main()
{
    while(1)
    {
        if(!getline(cin,str1))  return  0;
        if(!getline(cin,str2))  return  0;
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,0));
    }
    return  0;
}
