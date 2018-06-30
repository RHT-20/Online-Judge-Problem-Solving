#include<bits/stdc++.h>
using namespace std;

#define MX 255
int dp[MX][MX],freq[MX],sum[MX];

int get_sum(int l,int r)
{
    if(l>r) return  0;
    else    return  (sum[r]-sum[l-1]);
}

int solve(int l,int r)
{
    if(l>r) return  0;
    else if(dp[l][r]!=-1)   return  dp[l][r];
    int res=0,ans=INT_MAX;
    for(int i=l; i<=r; i++)
    {
        res = solve(l,i-1)+solve(i+1,r)+get_sum(l,i-1)+get_sum(i+1,r);
        ans = min(ans,res);
    }
    return  dp[l][r] = ans;
}

int main()
{
    int n,i;
    while(scanf("%d",&n)==1)
    {
        memset(freq,0,sizeof(freq));
        memset(sum,0,sizeof(sum));
        memset(dp,-1,sizeof(dp));
        for(i=1; i<=n; i++)
        {
            scanf("%d",&freq[i]);
            sum[i] = sum[i-1]+freq[i];
        }
        printf("%d\n",solve(1,n));
    }
    return  0;
}
