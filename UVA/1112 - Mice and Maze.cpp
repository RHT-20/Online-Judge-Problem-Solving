#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define IMX 20000000
#define pii pair<int,long long>
vector<pii>v[MX];
int dist[MX],n,tym,ans;
bool visited[MX];

struct node
{
    int x,w;
    bool operator < (node a)const
    {
        return  (a.w<w);
    }
};

void dijkstra(int s)
{
    priority_queue<node>pq;
    int w;
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
    ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(dist[i]<=tym)    ans++;
    }
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    fill(dist,dist+MX,IMX);
    memset(visited,false,sizeof(visited));
}

int main()
{
    int t,f=0,i,x,y,m,s,w;
    scanf("%d",&t);
    while(t--)
    {
        if(f)   puts("");
        f = 1;
        clr();
        scanf("%d %d %d %d",&n,&s,&tym,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            v[x].push_back(pii(y,w));
            v[y].push_back(pii(x,w));
        }
        dijkstra(s);
        printf("%d\n",ans);
    }
    return  0;
}
