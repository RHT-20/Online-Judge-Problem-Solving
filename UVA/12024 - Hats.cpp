#include<bits/stdc++.h>
using namespace std;

long long factorial[15],dp[15];

void pre()
{
    factorial[0] = 1;
    for(long long i=1; i<13; i++)   factorial[i] = factorial[i-1]*i;
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
    int t,n;
    scanf("%d",&t);
    pre();
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld/%lld\n",solve(n),factorial[n]);
    }
    return  0;
}
