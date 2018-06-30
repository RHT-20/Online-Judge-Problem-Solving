/// Solution-1
#include<bits/stdc++.h>
using namespace std;

#define MX 10005
#define IMX 100000005
#define pii pair<int,int>
pii dp[105][MX][105];
int visited[105][MX][105],coin[105],amount,n,cs;

pii solve(int pos,int sum,int cnt)
{
    if(pos>=n)
    {
        if(sum>=amount) return  pii(sum,cnt);
        else    return  pii(IMX,IMX);
    }
    else if(sum>=amount)    return  pii(sum,cnt);
    else if(visited[pos][sum][cnt]==cs)  return  dp[pos][sum][cnt];
    visited[pos][sum][cnt] = cs;
    pii res1,res2,ans;
    res1 = solve(pos+1,sum,cnt);
    res2 = solve(pos+1,sum+coin[pos],cnt+1);
    if(res1.first<res2.first)   ans = res1;
    else if(res2<res1)  ans = res2;
    else
    {
        if(res1.second<res2.second) ans = res1;
        else    ans = res2;
    }
    return  dp[pos][sum][cnt] = ans;
}

int main()
{
    int t,i;
    pii ans;
    cs = 0;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d %d",&amount,&n);
        for(i=0; i<n; i++)  scanf("%d",&coin[i]);
        ans = solve(0,0,0);
        printf("%d %d\n",ans.first,ans.second);
    }
    return  0;
}

/// Solution-2
#include<bits/stdc++.h>
using namespace std;

#define MX 10005
long long dp[105][MX],direction[105][MX],coin[105],amount,n;

long long solve_dp(long long pos,long long sum)
{
    if(pos>=n)
    {
        if(sum<=0) return  0;
        else    return  INT_MAX;
    }
    else if(sum<=0)    return  0;
    else if(dp[pos][sum]!=-1)   return  dp[pos][sum];
    long long res1=INT_MAX,res2=INT_MAX;
    res1 = solve_dp(pos+1,sum);
    res2 = coin[pos]+solve_dp(pos+1,sum-coin[pos]);
    dp[pos][sum] = min(res1,res2);
    return  dp[pos][sum];
}

long long solve_direction(long long pos,long long sum)
{
    if(pos>=n)
    {
        if(sum==0)  return  0;
        else    return  INT_MAX;
    }
    else if(sum==0) return  0;
    else if(direction[pos][sum]!=-1)    return  direction[pos][sum];
    long long res1=INT_MAX,res2=INT_MAX;
    res1 = solve_direction(pos+1,sum);
    if(sum>=coin[pos])  res2 = 1+solve_direction(pos+1,sum-coin[pos]);
    return  direction[pos][sum] = min(res1,res2);
}

int main()
{
    int t,i;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        memset(coin,0,sizeof(coin));
        memset(dp,-1,sizeof(dp));
        memset(direction,-1,sizeof(direction));
        scanf("%lld %lld",&amount,&n);
        for(i=0; i<n; i++)   scanf("%lld",&coin[i]);
        ans = solve_dp(0,amount);
        printf("%lld %lld\n",ans,solve_direction(0,ans));
    }
    return  0;
}

