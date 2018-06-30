#include<bits/stdc++.h>
using namespace std;

int dp[105][130000],coin[105],n,sum;

int solve(int pos,int amount)
{
    if(pos==n)  return abs(amount-(sum-amount));
    if(dp[pos][amount]!=-1) return dp[pos][amount];
    return dp[pos][amount] = min(solve(pos+1,amount),solve(pos+1,amount+coin[pos]));
}

int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(coin,0,sizeof(coin));
        sum = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&coin[i]);
            sum += coin[i];
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,0));
    }
    return 0;
}
