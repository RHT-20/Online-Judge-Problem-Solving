#include<bits/stdc++.h>
using namespace std;

int dp[35][1005],d[35],g[35],mt[35],ans[35],n,t,w;

void solve()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=t; j++)
        {
            if(mt[i]<=j)    dp[i][j] = max(dp[i-1][j],g[i]+dp[i-1][j-mt[i]]);
            else    dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n",dp[n][t]);
    int k = 0;
    memset(ans,0,sizeof(ans));
    i = n,j = t;
    while(i>0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            j = j-mt[i];
            ans[k++] = i;
        }
        i--;
    }
    printf("%d\n",k);
    for(i=k-1; i>=0; i--)
    {
        printf("%d %d\n",d[ans[i]],g[ans[i]]);
    }
}

int main()
{
    int i,y = 0;
    while(scanf("%d %d",&t,&w)!=EOF)
    {
        scanf("%d",&n);
        memset(d,0,sizeof(d));
        memset(g,0,sizeof(g));
        for(i=1; i<=n; i++)
        {
            scanf("%d %d",&d[i],&g[i]);
            mt[i] = 3*w*d[i];
        }
        if(y==1)    puts("");
        y = 1;
        solve();
    }
    return 0;
}
