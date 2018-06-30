#include<bits/stdc++.h>
using namespace std;

#define MX 1005
#define MOD 10056
long long dp1[MX][MX],dp2[MX];
int n;

long long nCr(int k,int r)
{
    if(k<r) return  0;
    else if(k==r || !r)   return  1;
    else if(r==1)   return  k;
    else if(dp1[k][r]!=-1)  return  dp1[k][r];

    long long res=0;
    res = (nCr(k-1,r)+nCr(k-1,r-1))%MOD;
    return  dp1[k][r] = res;
}

long long solve(int k)
{
    if(!k)  return  1;
    else if(dp2[k]!=-1) return  dp2[k];

    long long res=0;

    for(int i=k; i>0; i--)
    {
        res = (res+((nCr(k,i)*solve(k-i))%MOD))%MOD;
    }
    return  dp2[k] = res;
}

int main()
{
    int t,cs=0;
    scanf("%d",&t);
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    while(t--)
    {
        cs++;
        scanf("%d",&n);
        printf("Case %d: %lld\n",cs,solve(n));
    }
    return  0;
}
