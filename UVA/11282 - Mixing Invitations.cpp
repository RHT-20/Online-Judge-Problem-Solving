#include<bits/stdc++.h>
using namespace std;

long long factorial[22],dp[22];

void pre()
{
    factorial[0] = 1;
    for(long long i=1; i<21; i++)   factorial[i] = factorial[i-1]*i;
    return;
}

long long solve(int k)
{
    if(k==1)    return  0;
    else if(k==2)   return  1;
    else if(dp[k]!=-1)  return  dp[k];

    long long res=0;
    res = (k-1)*(solve(k-2)+solve(k-1));
    return  dp[k] = res;
}

int main()
{
    int n,k,i;
    long long ans,temp;
    memset(dp,-1,sizeof(dp));
    pre();
    while(scanf("%d %d",&n,&k)==2)
    {
        ans = 0;
        for(i=0; i<=k; i++)
        {
            temp = factorial[n];
            temp /= factorial[n-i];
            temp /= factorial[i];
            temp *= solve(n-i);
            ans += temp;
        }
        if(n==k)    ans++;
        printf("%lld\n",ans);
    }
    return  0;
}

