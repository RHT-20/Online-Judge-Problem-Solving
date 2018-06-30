#include<bits/stdc++.h>
using namespace std;

#define MX 1000005
vector<int>v[MX];
vector<long long>cost[MX];
int visited[MX];
long long sum;

struct kkk
{
    int x,y;
    long long w;
};

struct data
{
    int vertex;
    long long weight;
    bool operator < (data d) const
    {
        return  weight>d.weight;
    }
};

void minimum_spanning_tree_prims_algo(int s,int n)
{
    data d;
    priority_queue<data>pq;
    for(int j=0; j<n-1; j++)
    {
        visited[s] = 1;
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                d.vertex = v[s][i];
                d.weight = cost[s][i];
                pq.push(d);
            }
        }
        while(visited[s])
        {
            d = pq.top();
            pq.pop();
            s = d.vertex;
        }
        sum += d.weight;
    }
}

void clr()
{
    for(int i=0; i<MX; i++)
    {
        v[i].clear();
        cost[i].clear();
    }
}

int main()
{
    int i,n,e,x,y,k,m,f=0;
    long long w;
    while(scanf("%d",&n)!=EOF)
    {
        if(f)   puts("");
        f = 1;
        for(i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&x,&y,&w);
        }
        scanf("%d",&k);
        kkk km[k];
        for(i=0; i<k; i++)
        {
            scanf("%d %d %lld",&km[i].x,&km[i].y,&km[i].w);
        }
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            v[x].push_back(y);
            v[y].push_back(x);
            cost[x].push_back(w);
            cost[y].push_back(w);
        }
        sum = 0;
        memset(visited,0,sizeof(visited));
        minimum_spanning_tree_prims_algo(1,n);
        printf("%lld\n",sum);
        sum = 0;
        for(i=0; i<k; i++)
        {
            v[km[i].x].push_back(km[i].y);
            v[km[i].y].push_back(km[i].x);
            cost[km[i].x].push_back(km[i].w);
            cost[km[i].y].push_back(km[i].w);
        }
        memset(visited,0,sizeof(visited));
        minimum_spanning_tree_prims_algo(1,n);
        printf("%lld\n",sum);
        clr();
    }
    return 0;
}
