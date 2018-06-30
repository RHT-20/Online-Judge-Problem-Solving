#include<bits/stdc++.h>
using namespace std;

#define IMX 10000000
map<int,string>mp;
int a[25][25],dist[25],n;

int floyd_warshall()
{
    int mx,p;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++) a[i][j] = min(a[i][j],(a[i][k]+a[k][j]));
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) dist[i] += a[i][j];
    }
    mx = IMX;
    for(int i=1; i<=n; i++)
    {
        if(dist[i]<mx)
        {
            mx = dist[i];
            p = i;
        }
    }
    return  p;
}

void clr()
{
    for(int i=1; i<25; i++)
    {
        for(int j=1; j<25; j++)
        {
            if(i==j)    a[i][j] = 0;
            else    a[i][j] = IMX;
        }
    }
    mp.clear();
    memset(dist,0,sizeof(dist));
}

int main()
{
    int m,i,x,y,w,cs=0;
    char str[15];
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==0)    break;
        clr();
        cs++;
        for(i=1; i<=n; i++)
        {
            while(gets(str) && !str[0]);
            mp[i] = (string)str;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            a[x][y] = a[y][x] = w;
        }
        x = floyd_warshall();
        printf("Case #%d : ",cs);
        cout << mp[x] << endl;
    }
    return 0;
}
