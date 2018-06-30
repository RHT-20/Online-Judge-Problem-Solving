#include<bits/stdc++.h>
using namespace std;

int dp[100000],a[100000],n,k;

int solve(int u)
{
    if(dp[u]!=-1)   return dp[u];
    int mx=0,v;
    for(v=u+1; v<k; v++)
    {
        if(a[v]<a[u])
        {
            if(solve(v)>mx) mx = solve(v);
        }
    }
    return dp[u] = 1+mx;
}

int main()
{
    int cs=0;
    while(1)
    {
        int i;
        k = 0;
        while(1)
        {
            scanf("%d",&n);
            if(n==-1)   break;
            else    a[k++] = n;
        }
        if(k==0 && n==-1)   break;
        if(cs)  puts("");
        cs++;
        memset(dp,-1,sizeof(dp));
        int l = 0;
        for(i=0; i<k; i++)
        {
            if(solve(i)>l)  l = solve(i);
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n",cs,l);
    }
    return 0;
}
