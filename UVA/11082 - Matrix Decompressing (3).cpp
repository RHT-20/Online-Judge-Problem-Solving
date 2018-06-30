#include<bits/stdc++.h>
using namespace std;

#define MX 105
struct node
{
    int x,cf,i;
    node(){}
    node(int nx,int ncf,int ni)
    {
        x = nx;
        cf = ncf;
        i = ni;
    }
};
vector<node>v[MX];
int a[MX][MX],r[MX],c[MX],level[MX],n,m,s,t;
bool vis[MX];

bool BFS()
{
    queue<int>q;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    level[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = true;
        for(int i=0; i<v[x].size(); i++)
        {
            int y = v[x][i].x;
            int w = v[x][i].cf;
            if(w>0 && !vis[y])
            {
                vis[y] = true;
                level[y] = level[x]+1;
                q.push(y);
            }
        }
    }
    return  (level[t]!=-1);
}

int augmentation(int x,int flow)
{
    if(x==t)    return  flow;
    for(int i=0; i<v[x].size(); i++)
    {
        int y = v[x][i].x;
        int w = v[x][i].cf;
        if(w>0 && level[y]==(level[x]+1))
        {
            int current = min(flow,w);
            int temp = augmentation(y,current);
            if(temp>0)
            {
                v[x][i].cf -= temp;
                v[y][v[x][i].i].cf += temp;
                if(x!=s && x!=t && y!=s && y!=t)
                {
                    if(x<y) a[x][y-n] += temp;
                    else    a[y][x-n] -= temp;
                }
                return  temp;
            }
        }
    }
    return  0;
}

void DINIC()
{
    int flow=0;
    while(BFS())
    {
        while(1)
        {
            flow = augmentation(s,10000);
            if(flow<=0) break;
        }
    }
}

void print()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j>1) printf(" ");
            printf("%d",a[i][j]+1);
        }
        puts("");
    }
}

void build_graph()
{
    s = 0;
    t = n+m+1;
    for(int i=1; i<=n; i++) /// source to row
    {
        v[s].push_back(node(i,r[i],v[i].size()));
        v[i].push_back(node(s,0,v[s].size()-1));
    }
    for(int i=1; i<=n; i++) /// row to column
    {
        for(int j=(n+1); j<=(n+m); j++)
        {
            v[i].push_back(node(j,19,v[j].size()));
            v[j].push_back(node(i,0,v[i].size()-1));
        }
    }
    for(int i=(n+1); i<=(n+m); i++) /// column to sink
    {
        v[i].push_back(node(t,c[i-n],v[t].size()));
        v[t].push_back(node(i,0,v[i].size()-1));
    }
    /*for(int i=0; i<=t; i++)
    {
        printf("%d->\n",i);
        for(int j=0; j<v[i].size(); j++)
        {
            printf("%d - %d\n",v[i][j].x,v[i][j].cf);
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

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(a,0,sizeof(a));
}

int main()
{
    int ts,cs=0;
    scanf("%d",&ts);
    while(ts--)
    {
        if(cs)  puts("");
        cs++;
        clr();
        input();
        build_graph();
        DINIC();
        printf("Matrix %d\n",cs);
        print();
    }
    return  0;
}

