#include<bits/stdc++.h>
using namespace std;

#define MX 20005
#define pii pair<int,long long>
vector<pii>v[MX];
long long dist[MX];
bool visited[MX];

struct node
{
    int x;
    long long w;
    bool operator < (node a)const
    {
        return  (a.w<w);
    }
};

long long dijkstra(int s,int e)
{
    priority_queue<node>pq;
    long long w;
    node nd;
    nd.x = s;
    nd.w = 0;
    pq.push(nd);
    dist[s] = 0;
    while(!pq.empty())
    {
        nd = pq.top();
        pq.pop();
        s = nd.x;
        w = nd.w;
        if(s==e)    return  w;
        if(!visited[s])
        {
            visited[s] = true;
            for(int i=0; i<v[s].size(); i++)
            {
                if(dist[v[s][i].first]>(w+v[s][i].second))
                {
                    nd.x = v[s][i].first;
                    nd.w = v[s][i].second+w;
                    pq.push(nd);
                    dist[nd.x] = nd.w;
                }
            }
        }
    }
    return  -1;
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    fill(dist,dist+MX,INT_MAX);
    memset(visited,false,sizeof(visited));
}

int main()
{
    int t,cs=0,i,x,y,n,m,s,e;
    long long w;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        clr();
        scanf("%d %d %d %d",&n,&m,&s,&e);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            v[x].push_back(pii(y,w));
            v[y].push_back(pii(x,w));
        }
        w = dijkstra(s,e);
        if(w==-1)   printf("Case #%d: unreachable\n",cs);
        else    printf("Case #%d: %lld\n",cs,w);
    }
    return  0;
}
