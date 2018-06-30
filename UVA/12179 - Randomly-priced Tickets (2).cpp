#include<bits/stdc++.h>
using namespace std;

int a[105][105],dist,cost,n,r,c;
double dp[35][105][10005];///[range of r][path length][cost]

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

void solve_dp()
{
    for(int cc=1; cc<=30; cc++)
    {
        dp[cc][0][0] = 1.0;
        for(int i=1; i<=100; i++)
        {
            for(int j=0; j<=10000; j++)
            {
                for(int k=1; k<=cc; k++)
                {
                    if((j+k)>10000) break;
                    if(dp[cc][i-1][j]==0.0) break;
                    dp[cc][i][j+k] += (dp[cc][i-1][j]/(double)cc);
                }
            }
        }
    }
    return;
}

double calc()
{
    double res=0.0;
    for(int i=1; i<=cost; i++) res += dp[r][dist][i];
    return  res;
}

int main()
{
    int t,cs=0,i,j,sn,en;
    double ans;
    char str[105];
    scanf("%d",&t);
    solve_dp();
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
        //solve_dp();
        scanf("%d",&c);
        printf("Case %d\n",cs);
        for(i=0; i<c; i++)
        {
            scanf("%d %d %d",&sn,&en,&cost);
            dist = a[sn][en];
            ans = calc();
            if(dist>n)  ans = 0.0;
            printf("%0.6lf\n",ans);
        }
        puts("");
    }
    return  0;
}

