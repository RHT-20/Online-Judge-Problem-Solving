#include<bits/stdc++.h>
using namespace std;

vector<int>v;
int dp[10005][205],n,k;

int solve(int i,int w)
{
    if(i>=n)
    {
        if(w%k==0)  return  1;
        else    return  0;
    }
    else if(dp[i][w]!=-1)    return  dp[i][w];
    int res1=0,res2=0,x,y;
    x = w-100;
    y = (x+v[i])%k;
    y += 100;
    res1 = solve(i+1,y);
    y = x+((-1)*v[i]);
    y %= k;
    y += 100;
    res2 = solve(i+1,y);
    return  dp[i][w] = (res1|res2);
}

void clr()
{
    v.clear();
    memset(dp,-1,sizeof(dp));
}

int main()
{
    int t,i,w;
    scanf("%d",&t);
    while(t--)
    {
        clr();
        scanf("%d %d",&n,&k);
        for(i=0; i<n; i++)
        {
            scanf("%d",&w);
            v.push_back(w);
        }
        if(solve(0,0))  puts("Divisible");
        else    puts("Not divisible");
    }
    return  0;
}
