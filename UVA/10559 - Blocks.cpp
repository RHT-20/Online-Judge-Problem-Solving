#include<bits/stdc++.h>
using namespace std;

#define MX 205
int dp[MX][MX][MX],visited[MX][MX][MX],a[MX],cs;

int solve(int b,int e,int sum)
{
    if(b>e) return  0;
    else if(visited[b][e][sum]==cs) return  dp[b][e][sum];
    visited[b][e][sum] = cs;
    int res=0,ans=0;
    res += ((sum+1)*(sum+1))+solve(b+1,e,0);
    ans = max(ans,res);
    for(int i=(b+1); i<=e; i++)
    {
        if(a[b]==a[i])
        {
            res = solve(b+1,i-1,0)+solve(i,e,sum+1);
            ans = max(ans,res);
        }
    }
    return  dp[b][e][sum] = ans;
}

int main()
{
    int t,n,i;
    cs = 0;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(i=0; i<n; i++)  scanf("%d",&a[i]);
        printf("Case %d: %d\n",cs,solve(0,n-1,0));
    }
    return  0;
}
