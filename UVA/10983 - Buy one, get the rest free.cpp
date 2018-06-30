#include<bits/stdc++.h>
using namespace std;

#define MX 10005
#define INF 100000
int node1[MX],node2[MX],capacity[MX],flow[MX];
int pre_pos[MX],last_pos[MX],recent[MX];
int que[MX],level[MX];
int edge_cnt,source,sink;
int n,m,day;
int tot_man[35],people;

struct flight
{
    int x,y,c,p,e;
};
vector<flight>flightv;

void init()
{
    source = 0;
    sink = (n*(day+2))+1;
    memset(last_pos,-1,sizeof(last_pos));
    edge_cnt = 0;
    return;
}

void add_edge(int x,int y,int cap)
{
    /// forward edge
    node1[edge_cnt] = x;
    node2[edge_cnt] = y;
    capacity[edge_cnt] = cap;
    flow[edge_cnt] = 0;
    pre_pos[edge_cnt] = last_pos[x];
    last_pos[x] = edge_cnt;

    edge_cnt++;

    /// reverse edge
    node1[edge_cnt] = y;
    node2[edge_cnt] = x;
    capacity[edge_cnt] = 0;
    flow[edge_cnt] = 0;
    pre_pos[edge_cnt] = last_pos[y];
    last_pos[y] = edge_cnt;

    edge_cnt++;
    return;
}

bool BFS()
{
    int l=0,r=0,x,y,i;
    memset(level,-1,sizeof(level));

    que[r++] = source;
    level[source] = 0;

    while(l<r)
    {
        x = que[l++];
        if(x==sink)    return  true;

        for(i=last_pos[x]; i>=0; i=pre_pos[i])
        {
            y = node2[i];
            if(capacity[i]>0 && level[y]==-1)
            {
                level[y] = level[x]+1;
                que[r++] = y;
            }
        }
    }
    return  false;
}

int DFS(int x,int flw)
{
    if(x==sink)    return  flw;

    for(int &i=recent[x]; i>=0; i=pre_pos[i])
    {
        int y = node2[i];
        int cur_flw = min(flw,capacity[i]);

        if(level[y]==(level[x]+1) && cur_flw>0)
        {
            cur_flw = DFS(y,cur_flw);
            if(cur_flw>0)
            {
                capacity[i] -= cur_flw;
                flow[i] += cur_flw;
                capacity[i^1] += cur_flw;
                return  cur_flw;
            }
        }
    }
    return  0;
}

int DINIC()
{
    int tot=0,ret;
    while(BFS())
    {
        for(int i=source; i<=sink; i++) recent[i] = last_pos[i];
        while(1)
        {
            ret = DFS(source,INF);
            if(!ret)    break;
            tot += ret;
        }
    }
    return  tot;
}

void build(int lim)
{
    init();
    for(int i=1; i<=n; i++) add_edge(source,i,tot_man[i]);
    for(int i=0; i<(int)flightv.size(); i++)
    {
        if(flightv[i].p<=lim && flightv[i].e<day)
        {
            int x = flightv[i].x+(n*(flightv[i].e+1));   /// (city,day)
            int y = flightv[i].y+(n*(flightv[i].e+2));
            add_edge(x,y,flightv[i].c);
        }
    }
    for(int i=1; i<=n; i++)
    {
        int x = i;
        for(int j=0; j<day; j++)
        {
            int y = i+(n*(j+1));
            add_edge(x,y,INF);
            x = y;
        }
    }
    add_edge((n*(day+1)),(n*(day+2)),INF);
    add_edge((n*(day+2)),sink,INF);
    return;
}

int BS()
{
    int lo=0,hi=100000,mid,res=-1;
    while(lo<=hi)
    {
        mid = (lo+hi)>>1;
        build(mid);
        if(DINIC()>=people)
        {
            res = mid;
            hi = mid-1;
        }
        else    lo = mid+1;
        //cout<<mid<<" "<<lo<<" "<<hi<<endl;
    }
    return  res;
}

void clr()
{
    people = 0;
    flightv.clear();
    //for(int i=0; i<MX; i++) v[i].clear();
    return;
}

int main()
{
    int t,cs=0,i,res;
    flight ft;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        clr();
        scanf("%d %d %d",&n,&day,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d %d %d",&ft.x,&ft.y,&ft.c,&ft.p,&ft.e);
            flightv.push_back(ft);
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&tot_man[i]);
            people += tot_man[i];
        }
        printf("Case #%d: ",cs);
        res = BS();
        if(res==-1) puts("Impossible");
        else    printf("%d\n",res);
    }
    return  0;
}
