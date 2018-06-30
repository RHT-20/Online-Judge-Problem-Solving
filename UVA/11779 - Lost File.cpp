#include<bits/stdc++.h>
using namespace std;

#define MX 55
int a[MX][MX],n;

void floyd_warshall()
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                a[i][j] -= (a[i][k]*a[k][j]);
            }
        }
    }
}

int main()
{
    int t,cs=0,m,x,y,w,i,j;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        memset(a,0,sizeof(a));
        scanf("%d %d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            a[x][y] = w;
        }
        floyd_warshall();
        m = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)  if(a[i][j]) m++;
        }
        printf("Case %d: %d %d\n",cs,n,m);
        for(i=0; i<n; i++)
        {
            m = 0;
            for(j=0; j<n; j++)  if(a[i][j]) m++;
            printf("%d",m);
            for(j=0; j<n; j++)  if(a[i][j]) printf(" %d",j);
            puts("");
        }
    }
    return  0;
}

