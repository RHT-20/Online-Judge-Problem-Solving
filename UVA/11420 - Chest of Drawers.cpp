#include<bits/stdc++.h>
using namespace std;

#define MX 70
long long dp[MX][MX][3];
int n,k;

long long solve(int pos,int save,int lock)
{
    if(pos>=n) return  (save==k);
    else if(dp[pos][save][lock]!=-1)    return  dp[pos][save][lock];
    long long res=0;
    /// current position unlock
    res += solve(pos+1,save,0);
    /// current position lock
    if(pos==0)  res += solve(pos+1,save+1,1);
    else
    {
        if(lock)    res += solve(pos+1,save+1,1);
        else    res += solve(pos+1,save,1);
    }
    return  dp[pos][save][lock] = res;
}

int main()
{
    while(1)
    {
        scanf("%d %d",&n,&k);
        if(n<0 && k<0)  break;
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(0,0,0));
    }
    return  0;
}
