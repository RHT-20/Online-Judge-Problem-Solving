#include<bits/stdc++.h>
using namespace std;

#define MX 1000
int a[25][25];

void floyd_warshall()
{
    for(int k=1; k<=20; k++)
    {
        for(int i=1; i<=20; i++)
        {
            for(int j=1; j<=20; j++)
            {
                a[i][j] = min(a[i][j],(a[i][k]+a[k][j]));
            }
        }
    }
}

int main()
{
    int n,x,y,cs=0,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        cs++;
        memset(a,0,sizeof(a));
        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            a[1][x] = a[x][1] = 1;
        }
        for(i=2; i<20; i++)
        {
            scanf("%d",&n);
            for(j=0; j<n; j++)
            {
                scanf("%d",&x);
                a[i][x] = a[x][i] = 1;
            }
        }
        for(i=1; i<=20; i++)
        {
            for(j=1; j<=20; j++)
            {
                if(a[i][j]==0)  a[i][j] = a[j][i] = MX;
            }
        }
        floyd_warshall();
        scanf("%d",&n);
        printf("Test Set #%d\n",cs);
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            printf("%2d to %2d: %d\n",x,y,a[x][y]);
        }
        puts("");
    }
    return 0;
}
