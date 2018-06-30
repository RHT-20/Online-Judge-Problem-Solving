#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define MOD 1000000
long long dp[MX][MX];

long long solve(int n,int k)
{
    if(k==0)
    {
        if(n==0)    return  1;
        else    return  0;
    }
    else if(dp[n][k]!=-1)   return  dp[n][k];
    long long ans=0;
    for(int i=0; i<=n; i++) ans = (ans+solve(n-i,k-1))%MOD;
    return  dp[n][k] = ans;
}

int main()
{
    int n,k;
    while(1)
    {
        scanf("%d %d",&n,&k);
        if(!n && !k)    break;
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(n,k));
    }
    return  0;
}
