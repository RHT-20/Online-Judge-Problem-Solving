#include<bits/stdc++.h>
using namespace std;

#define MX 105
int a[MX][MX],path[MX],r[MX],c[MX],n,m,s,t;
bool vis[MX];

bool BFS()
{
    queue<int>q;
    memset(vis,false,sizeof(vis));
    memset(path,-1,sizeof(path));
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = true;
        for(int i=s; i<=t; i++)
        {
            if(a[x][i]>0 && !vis[i])
            {
                vis[i] = true;
                path[i] = x;
                q.push(i);
                if(i==t)    return  true;
            }
        }
    }
    return  false;
}

void augmentation()
{
    int x=t,y,flow=10000;
    while(1)
    {
        y = path[x];
        if(y==-1) break;
        flow = min(flow,a[y][x]);
        x = y;
    }
    x = t;
    while(1)
    {
        y = path[x];
        if(y==-1)   break;
        a[y][x] -= flow;
        a[x][y] += flow;
        x = y;
    }
}

void FORD_FULKERSON()
{
    while(BFS())
    {
        augmentation();
    }
}

void print()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=(n+1); j<=(n+m); j++)
        {
            if(j>(n+1)) printf(" ");
            printf("%d",(20-a[i][j]));
        }
        puts("");
    }
}

void build_graph()
{
    s = 0;
    t = n+m+1;
    memset(a,0,sizeof(a));
    for(int i=1; i<=n; i++) /// source to row
    {
        a[s][i] = r[i];
        a[i][s] = 0;
    }
    for(int i=1; i<=n; i++) /// row to column
    {
        for(int j=(n+1); j<=(n+m); j++)
        {
            a[i][j] = 19;
            a[j][i] = 0;
        }
    }
    for(int i=(n+1); i<=(n+m); i++) /// column to sink
    {
        a[i][t] = c[i-n];
        a[t][i] = 0;
    }
    /*for(int i=0; i<=t; i++)
    {
        printf("%d->\n",i);
        for(int j=0; j<=t; j++)
        {
            if(a[i][j])
            {
                printf("%d - %d\n",j,a[i][j]);
                puts("");
            }
        }
    }*/
}

void input()
{
    int x,y,i;
    scanf("%d %d",&n,&m);
    x = 0;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&r[i]);
        y = r[i];
        r[i] -= x;
        r[i] -= m;
        x = y;
    }
    x = 0;
    for(i=1; i<=m; i++)
    {
        scanf("%d",&c[i]);
        y = c[i];
        c[i] -= x;
        c[i] -= n;
        x = y;
    }
}

int main()
{
    int ts,cs=0;
    scanf("%d",&ts);
    while(ts--)
    {
        if(cs)  puts("");
        cs++;
        input();
        build_graph();
        FORD_FULKERSON();
        printf("Matrix %d\n",cs);
        print();
    }
    return  0;
}

