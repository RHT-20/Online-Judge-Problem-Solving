#include<bits/stdc++.h>
using namespace std;

#define MX 55
int n,k;
unsigned long long int dp[MX][MX][3];

unsigned long long int solve(int small,int large,bool last)
{
    if(!small && !large)    return  1;
    else if(small<0 || large<0) return  0;
    else if(dp[small][large][last]!=-1)  return  dp[small][large][last];

    unsigned long long int res=0;

    if(last)    /// previous large
    {
        for(int i=1; i<=small; i++)
        {
            res += solve(i-1,large+(small-i),false);
        }
    }
    else    /// previous small
    {
        for(int i=1; i<=large; i++)
        {
            res += solve(small+(i-1),large-i,true);
        }
    }
    return  dp[small][large][last] = res;
}

int main()
{
    unsigned long long int ans;
    while(scanf("%d %d",&n,&k)==2)
    {
        memset(dp,-1,sizeof(dp));
        if(k==1)    ans = solve(1,n-3,true);
        else    ans = solve(k-1,n-k,true);
        printf("%llu\n",max(1ULL,ans));
    }
    return  0;
}
