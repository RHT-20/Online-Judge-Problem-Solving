#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ppi pair<pii,long long>
#define MX 10005

int n,m;
ppi edge[MX];
long long dist[MX];

bool bellman_ford(int s)
{
    int u,v;
    long long w;
    dist[s] = 0;
    for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<m; j++)
        {
            u = edge[j].first.first;
            v = edge[j].first.second;
            w = edge[j].second;
            if((dist[u]+w)<dist[v]) dist[v] = dist[u]+w;
        }
    }
    for(int i=0; i<m; i++)
    {
        u = edge[i].first.first;
        v = edge[i].first.second;
        w = edge[i].second;
        if((dist[u]+w)<dist[v]) return  false;
    }
    return  true;
}

void clr()
{
    for(int i=0; i<MX; i++) dist[i] = INT_MAX;
    memset(edge,0,sizeof(edge));
}

int main()
{
    int t,x,y,i;
    long long w;
    scanf("%d",&t);
    while(t--)
    {
        clr();
        scanf("%d %d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            edge[i].first.first = x;
            edge[i].first.second = y;
            edge[i].second = w;
        }
        x = 0;
        if(!bellman_ford(x))    printf("possible\n");
        else    printf("not possible\n");
    }
    return  0;
}

//if there exists negative cycle it is possible to go past else impossible
