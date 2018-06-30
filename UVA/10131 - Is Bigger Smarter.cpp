#include<bits/stdc++.h>
using namespace std;

int dp[1005],dr[1005],c,w[1005],s[1005];

int solve(int pos)
{
    if(pos==c)  return 0;
    if(dp[pos]!=-1) return dp[pos];
    int mx = 0;
    for(int i=0; i<c; i++)
    {
        if(w[i]>w[pos] && s[i]<s[pos])
        {
            if(solve(i)>mx)
            {
                mx = solve(i);
                dr[pos] = i;
            }
        }
    }
    return dp[pos] = mx+1;
}

int main()
{
    int a,b;
    c = 0;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        w[c] = a;
        s[c++] = b;
    }
    memset(dp,-1,sizeof(dp));
    memset(dr,-1,sizeof(dr));
    int l=0,i,start;
    for(i=0; i<c; i++)
    {
        if(solve(i)>l)
        {
            l = solve(i);
            start = i;
        }
    }
    printf("%d\n",l);
    while(1)
    {
        printf("%d\n",start+1);
        if(dr[start]==-1)   break;
        start = dr[start];
    }
    return 0;
}
