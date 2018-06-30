#include<bits/stdc++.h>
using namespace std;

int a[105][105],dist,cost,n,r,c;
double dp[105][3005];
bool vis[105][3005];

void Floyd_Warshall()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                a[i][j] = min(a[i][j],(a[i][k]+a[k][j]));
            }
        }
    }
    return;
}

double solve_dp(int pos,int w)
{
    if(w>cost) return  0;
    else if(pos>=dist)  return  1.0;
    else if(vis[pos][w])    return  dp[pos][w];
    vis[pos][w] = true;

    double res=0.0;
    for(int i=1; i<=r; i++)
    {
        res += solve_dp(pos+1,w+i)/(double)r;
    }
    return  dp[pos][w] = res;
}

int main()
{
    int t,cs=0,i,j,sn,en;
    double ans;
    char str[105];
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d %d",&n,&r);
        for(i=1; i<=n; i++)
        {
            while(gets(str) && !str[0]);
            for(j=0; str[j]; j++)
            {
                if(str[j]=='N') a[i][j+1] = 500;
                else    a[i][j+1] = 1;
            }
        }
        Floyd_Warshall();
        scanf("%d",&c);
        printf("Case %d\n",cs);
        for(i=0; i<c; i++)
        {
            scanf("%d %d %d",&sn,&en,&cost);
            memset(vis,false,sizeof(vis));
            dist = a[sn][en];
            ans = solve_dp(0,0);
            if(dist>n)  ans = 0.0;
            printf("%0.6lf\n",ans);
        }
        puts("");
    }
    return  0;
}

