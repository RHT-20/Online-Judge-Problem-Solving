#include<bits/stdc++.h>
using namespace std;

#define MX 205
#define pii pair<int,int>
#define ppi pair<pii,long long>
vector<ppi>edge;
long long dist[MX],buy[MX];
int n,m;

void bellman_ford()
{
    int u,v,f;
    long long w;
    dist[1] = 0;
    for(int i=1; i<n; i++)
    {
        f = 0;
        for(int j=0; j<edge.size(); j++)
        {
            u = edge[j].first.first;
            v = edge[j].first.second;
            w = edge[j].second;
            if((dist[u]+w)<dist[v] && dist[u]!=INT_MAX)
            {
                dist[v] = dist[u]+w;
                f = 1;
            }
        }
        if(f==0)    break;
    }
    memset(buy,0,sizeof(buy));
    for(int i=0; i<edge.size(); i++)
    {
        u = edge[i].first.first;
        v = edge[i].first.second;
        w = edge[i].second;
        if((dist[u]+w)<dist[v] && dist[u]!=INT_MAX)
        {
            dist[v] = dist[u]+w;
            buy[v] = 1;
        }
    }
}

void clr()
{
    fill(dist,dist+MX,INT_MAX);
    memset(buy,0,sizeof(buy));
    edge.clear();
}

int main()
{
    int i,q,x,y,cs=0;
    ppi p;
    long long w;
    while(scanf("%d",&n)==1)
    {
        cs++;
        clr();
        for(i=1; i<=n; i++) scanf("%lld",&buy[i]);
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            p.first.first = x;
            p.first.second = y;
            w = buy[y]-buy[x];
            p.second = w*w*w;
            edge.push_back(p);
        }
        bellman_ford();
        scanf("%d",&q);
        printf("Set #%d\n",cs);
        while(q--)
        {
            scanf("%d",&x);
            if(dist[x]<3 || buy[x] || dist[x]==INT_MAX)   printf("?\n");
            else    printf("%lld\n",dist[x]);
        }
    }
    return 0;
}
