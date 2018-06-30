#include<bits/stdc++.h>
using namespace std;

long long a[85][85],fest[85][85];
int n;

void floyd_warshall()
{
    long long mx,f;
    while(1)
    {
        f = 0;
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    mx = max(fest[i][k],fest[k][j]);
                    if((a[i][j]+fest[i][j])>(a[i][k]+a[k][j]+mx))
                    {
                        a[i][j] = a[i][k]+a[k][j];
                        fest[i][j] = mx;
                        f = 1;
                    }
                }
            }
        }
        if(f==0)    break;
    }
}

void clr()
{
    for(int i=0; i<85; i++)
    {
        for(int j=0; j<85; j++)
        {
            if(i==j)    fest[i][j] = a[i][j] = 0;
            else    fest[i][j] = a[i][j] = INT_MAX;
        }
    }
}

int main()
{
    int cs=0,m,q,x,y,i;
    long long w;
    while(1)
    {
        scanf("%d %d %d",&n,&m,&q);
        if(n==0 && m==0 && q==0)    break;
        if(cs)  puts("");
        cs++;
        clr();
        for(i=1; i<=n; i++) scanf("%lld",&fest[i][i]);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            a[x][y] = a[y][x] = w;
            fest[x][y] = fest[y][x] = max(fest[x][x],fest[y][y]);
        }
        floyd_warshall();
        printf("Case #%d\n",cs);
        for(i=0; i<q; i++)
        {
            scanf("%d %d",&x,&y);
            if(a[x][y]==INT_MAX)    printf("-1\n");
            else    printf("%lld\n",(a[x][y]+fest[x][y]));
        }
    }
    return  0;
}
