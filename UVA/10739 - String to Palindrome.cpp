#include<bits/stdc++.h>
using namespace std;

#define MX 1005
string str;
int dp[MX][MX];

int solve(int i,int j)
{
    if(i>=j) return  0;
    else if(dp[i][j]!=-1)   return  dp[i][j];
    int res=0;
    if(str[i]==str[j])  res = solve(i+1,j-1);
    else    res = 1+min(solve(i+1,j),min(solve(i,j-1),solve(i+1,j-1)));
    return  dp[i][j] = res;
}

int main()
{
    int t,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        cin >> str;
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",cs,solve(0,str.size()-1));
    }
    return  0;
}
