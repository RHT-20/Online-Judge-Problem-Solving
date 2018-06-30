#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define IMX 200000000
int a[MX][MX],n;

void floyd_warshall()
{
    int f,w;
    while(1)
    {
        f = 0;
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    w = max(a[i][k],a[k][j]);
                    if(a[i][j]>w)
                    {
                        a[i][j] = w;
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
    for(int i=0; i<MX; i++)
    {
        for(int j=0; j<MX; j++)
        {
            if(i==j)    a[i][j] = 0;
            else    a[i][j] = IMX;
        }
    }
}

int main()
{
    int m,q,x,y,w,i,cs=0;
    while(1)
    {
        clr();
        scanf("%d %d %d",&n,&m,&q);
        if(!n && !m && !q)  break;
        if(cs)  puts("");
        cs++;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            a[x][y] = a[y][x] = w;
        }
        floyd_warshall();
        printf("Case #%d\n",cs);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            if(a[x][y]==IMX)    puts("no path");
            else    printf("%d\n",a[x][y]);
        }
    }
    return  0;
}
