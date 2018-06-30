#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define pii pair<int,long long>
struct node
{
    int x,c;
    long long w;
    bool operator <(node a)const
    {
        return  (a.w<w);
    }
};
map<string,int>mp;
vector<pii>v[MX];
int n,m,chnc;
long long dist[MX][MX],ans;

bool dijkstra()
{
    int s,c,i;
    long long w;
    node nd;
    priority_queue<node>pq;
    for(i=0; i<MX; i++) fill(dist[i],dist[i]+MX,INT_MAX);
    nd.x = 1;
    nd.c = 0;
    nd.w = 0;
    pq.push(nd);
    dist[0][1] = 0;
    while(!pq.empty())
    {
        nd = pq.top();
        pq.pop();
        s = nd.x;
        c = nd.c;
        w = nd.w;
        for(i=0; i<v[s].size(); i++)
        {
            if(dist[c+1][v[s][i].first]>(w+v[s][i].second))
            {
                nd.x = v[s][i].first;
                nd.w = w+v[s][i].second;
                nd.c = c+1;
                dist[c+1][nd.x] = nd.w;
                pq.push(nd);
            }
        }
    }
    ans = INT_MAX;
    for(i=0; i<=min(n-1,chnc+1); i++)  ans = min(ans,dist[i][n]);
    if(ans==INT_MAX)    return  false;
    else    return  true;
}

void clr()
{
    mp.clear();
    for(int i=0; i<MX; i++) v[i].clear();
}

int main()
{
    int t,cs=0,i,q;
    char str1[MX],str2[MX];
    long long w;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        clr();
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%s",str1);
            mp[(string)str1] = i;
        }
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf("%s %s %lld",str1,str2,&w);
            v[mp[(string)str1]].push_back(pii(mp[(string)str2],w));
        }
        scanf("%d",&q);
        printf("Scenario #%d\n",cs);
        while(q--)
        {
            scanf("%d",&chnc);
            if(dijkstra())  printf("Total cost of flight(s) is $%lld\n",ans);
            else    puts("No satisfactory flights");
        }
        if(t)   puts("");
    }
    return  0;
}
