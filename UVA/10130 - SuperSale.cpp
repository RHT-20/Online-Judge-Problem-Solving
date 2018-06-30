#include<bits/stdc++.h>
using namespace std;

int dp[1005][35],p[1005],w[1005],n;

int solve(int pos,int amount)
{
    if(pos==n)  return 0;
    if(dp[pos][amount]!=-1) return dp[pos][amount];
    int c1=0,c2=0;
    if(w[pos]<=amount)  c1 = p[pos]+solve(pos+1,amount-w[pos]);
    c2 = solve(pos+1,amount);
    return dp[pos][amount] = max(c1,c2);
}

int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(p,0,sizeof(p));
        memset(w,0,sizeof(w));
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&p[i],&w[i]);
        }
        int g,mw,sum=0;
        scanf("%d",&g);
        for(i=0; i<g; i++)
        {
            scanf("%d",&mw);
            memset(dp,-1,sizeof(dp));
            sum += solve(0,mw);
        }
        printf("%d\n",sum);
    }
    return 0;
}
