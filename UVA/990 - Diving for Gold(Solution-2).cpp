#include<bits/stdc++.h>
using namespace std;

#define MX 1005
#define pii pair<int,int>
vector<pii>v;
int dp[35][MX],direction[35][MX],cnst,n;
pii weight[MX];

int solve(int i,int w)
{
    if(i>=n)    return  0;
    else if(dp[i][w]!=-1)   return  dp[i][w];
    int res1=0,res2=0,x;
    x = 3*(weight[i].first*cnst);
    if((w-x)>=0)    res1 = weight[i].second+solve(i+1,(w-x));
    res2 = solve(i+1,w);
    if(res1>res2)
    {
        dp[i][w] = res1;
        direction[i][w] = 1;
    }
    else
    {
        dp[i][w] = res2;
        direction[i][w] = 2;
    }
    return  dp[i][w];
}

void path(int i,int w)
{
    v.clear();
    while(direction[i][w]!=-1)
    {
        if(direction[i][w]==1)
        {
            v.push_back(pii(weight[i].first,weight[i].second));
            w -= 3*(weight[i].first*cnst);
            i++;
        }
        else    i++;
    }
    printf("%d\n",v.size());
    for(int i=0; i<v.size(); i++)   printf("%d %d\n",v[i].first,v[i].second);
}

int main()
{
    int i,tym,f=0;
    while(scanf("%d %d",&tym,&cnst)==2)
    {
        if(f)   puts("");
        f = 1;
        memset(weight,0,sizeof(weight));
        scanf("%d",&n);
        for(i=0; i<n; i++)  scanf("%d %d",&weight[i].first,&weight[i].second);
        memset(dp,-1,sizeof(dp));
        memset(direction,-1,sizeof(direction));
        solve(0,tym);
        printf("%d\n",dp[0][tym]);
        path(0,tym);
    }
    return  0;
}
