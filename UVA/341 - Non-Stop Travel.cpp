#include<bits/stdc++.h>
using namespace std;

int a[15][15],path[15][15],n;

void floyd_warshall()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i][j]>(a[i][k]+a[k][j]))
                {
                    a[i][j] = a[i][k]+a[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}

void print_path(int x,int y)
{
    while(x!=y)
    {
        x = path[x][y];
        printf(" %d",x);
    }
}

int main()
{
    int i,j,cs=0,m,x,y;
    while(1)
    {
        scanf("%d",&n);
        if(!n)  break;
        cs++;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++) a[i][j] = 100000000;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(j=0; j<m; j++)
            {
                scanf("%d %d",&x,&y);
                a[i][x] = y;
                path[i][x] = x;
            }
        }
        floyd_warshall();
        scanf("%d %d",&x,&y);
        printf("Case %d: Path = %d",cs,x);
        print_path(x,y);
        printf("; %d second delay\n",a[x][y]);
        memset(a,0,sizeof(a));
        memset(path,0,sizeof(path));
    }
    return 0;
}
