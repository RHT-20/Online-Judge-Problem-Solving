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
node path[MX];
int a[MX][MX],r[MX],c[MX],n,m,s,t;
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
        for(int i=0; i<v[x].size(); i++)
        {
            int y = v[x][i].x;
            int w = v[x][i].cf;
            if(w>0 && !vis[y])
            {
                vis[y] = true;
                path[y] = node(x,w,i);
                q.push(y);
                if(y==t)    return  true;
            }
        }
    }
    return  false;
}

void augmentation()
{
    int x=t,y,w,flow=10000;
    while(1)
    {
        y = path[x].x;
        w = path[x].cf;
        if(y==-1) break;
        flow = min(flow,w);
        x = y;
    }
    x = t;
    while(1)
    {
        y = path[x].x;
        if(y==-1)   break;
        v[y][path[x].i].cf -= flow;
        v[x][v[y][path[x].i].i].cf += flow;
        if(x>s && x<t && y>s && y<t)
        {
            if(x>n) a[y][x-n] += flow;
            else    a[x][y-n] -= flow;
        }
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
        FORD_FULKERSON();
        printf("Matrix %d\n",cs);
        print();
    }
    return  0;
}

