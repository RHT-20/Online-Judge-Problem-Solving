#include<bits/stdc++.h>
using namespace std;

int n,k;
long long dp[65][35][105];

long long solve(int pos,int one,long long mod)
{
    if(one==0)  return  (mod==0);
    else if(pos<0)  return  0;
    else if(dp[pos][one][mod]!=-1)  return  dp[pos][one][mod];
    long long res=0,x=1;
    x <<= pos;
    x %= k;
    x = (x+mod)%k;
    res += solve(pos-1,one-1,x);
    res += solve(pos-1,one,mod);
    return  dp[pos][one][mod] = res;
}

int main()
{
    int t,cs=0;
    long long ans;
    unsigned long long x;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d %d",&n,&k);
        if(n%2 || k==0) ans = 0;
        else
        {
            x = 1;
            x <<= (n-1);    /// 1 fixed in the first position
            x %= k;
            memset(dp,-1,sizeof(dp));
            ans = solve(n-2,(n/2)-1,x);
        }
        printf("Case %d: %lld\n",cs,ans);
    }
    return  0;
}
