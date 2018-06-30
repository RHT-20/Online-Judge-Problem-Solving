#include<bits/stdc++.h>
using namespace std;

long long dp[25][10005];
int coin[25];

long long solve(int pos,int amount)
{
    if(pos==22) return (bool)(amount==0);
    if(amount==0)   return 1;
    else if(amount<0)   return 0;
    if(dp[pos][amount]!=-1) return dp[pos][amount];
    return dp[pos][amount] = solve(pos,amount-coin[pos])+solve(pos+1,amount);
}

int main()
{
    int n,i;
    for(i=0; i<22; i++)
    {
        coin[i] = i*i*i;
    }
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(1,n));
    }
    return 0;
}
