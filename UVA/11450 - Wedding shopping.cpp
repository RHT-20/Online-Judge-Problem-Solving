#include<bits/stdc++.h>
using namespace std;

vector<int>v[22];
int dp[22][22][205],amount,n;

int solve(int i,int j,int w)
{
    if(i>=n || j>=v[i].size())  return  0;
    else if(dp[i][j][w]!=-1)    return  dp[i][j][w];
    int res1=0,res2=0;
    res1 = solve(i,j+1,w);
    if(w>=v[i][j])  res2 = v[i][j]+solve(i+1,0,(w-v[i][j]));
    return  dp[i][j][w] = max(res1,res2);
}

void clr()
{
    for(int i=0; i<22; i++) v[i].clear();
    memset(dp,-1,sizeof(dp));
}

int main()
{
    int t,m,i,w;
    scanf("%d",&t);
    while(t--)
    {
        clr();
        scanf("%d %d",&amount,&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&w);
                v[i].push_back(w);
            }
            sort(v[i].begin(),v[i].end());
        }
        w = 0;
        for(i=0; i<n; i++)  w += v[i][0];
        if(w>amount)    puts("no solution");
        else    printf("%d\n",solve(0,0,amount));
    }
    return  0;
}
