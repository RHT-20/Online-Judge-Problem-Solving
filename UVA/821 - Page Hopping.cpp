#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define IMX 1000000
int a[MX][MX],c[MX],v,ans;

void floyd_warshall()
{
    for(int k=1; k<=100; k++)
    {
        if(c[k]==0) continue;
        for(int i=1; i<=100; i++)
        {
            if(c[i]==0) continue;
            for(int j=1; j<=100; j++)
            {
                if(c[j]==0) continue;
                a[i][j] = min(a[i][j],(a[i][k]+a[k][j]));
            }
        }
    }
    for(int i=1; i<=100; i++)
    {
        if(c[i]==0) continue;
        for(int j=1; j<=100; j++)
        {
            if(c[j]==0) continue;
            if(a[i][j]==IMX)    continue;
            else    ans += a[i][j];
        }
    }
}

void clr()
{
    v = 0;
    ans = 0;
    memset(a,0,sizeof(a));
    for(int i=0; i<MX; i++)
    {
        for(int j=0; j<MX; j++)
        {
            if(i==j)    continue;
            a[i][j] = IMX;
        }
    }
    memset(c,0,sizeof(c));
}

int main()
{
    int x,y,cs=0;
    double w;
    while(1)
    {
        cs++;
        clr();
        scanf("%d %d",&x,&y);
        if(x==0 && y==0)    break;
        while(1)
        {
            if(c[x]==0)
            {
                v++;
                c[x] = 1;
            }
            if(c[y]==0)
            {
                v++;
                c[y] = 1;
            }
            a[x][y] = 1;
            scanf("%d %d",&x,&y);
            if(x==0 && y==0)    break;
        }
        floyd_warshall();
        v = v*(v-1);
        w = (double)ans/(double)v;
        printf("Case %d: average length between pages = %0.3lf clicks\n",cs,w);
    }
    return 0;
}
