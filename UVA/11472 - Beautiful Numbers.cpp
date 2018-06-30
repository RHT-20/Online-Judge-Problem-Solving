#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define MOD 1000000007
int n,m;
long long dp[MX][1<<12][12];
int vis[MX][1<<12][12],c;

int set_bit(int mask,int pos){  return  (mask | (1<<pos));}

long long solve(int pos,int mask,int last,int len)
{
    if(pos>=len)
    {
        if(mask==((1<<n)-1))    return  1;
        else    return  0;
    }
    else if(vis[pos][mask][last]==c) return  dp[pos][mask][last];
    vis[pos][mask][last] = c;

    long long res=0;

    for(int i=0; i<n; i++)
    {
        if(!pos && i)   res = (res+solve(pos+1,set_bit(mask,i),i,len))%MOD;
        else if(pos && abs(last-i)==1)  res = (res+solve(pos+1,set_bit(mask,i),i,len))%MOD;
    }
    return  dp[pos][mask][last] = res;
}

int main()
{
    int t;
    c = 0;
    long long res;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        res = 0;
        for(int i=n; i<=m; i++)
        {
            c++;
            res = (res+solve(0,0,0,i))%MOD;
        }
        printf("%lld\n",res);
    }
    return  0;
}
