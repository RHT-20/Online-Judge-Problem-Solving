#include<bits/stdc++.h>
using namespace std;

#define MX 50005
long long dist[MX],ans;
int n,graph[MX],visited[MX],pos;

long long dfs(int s)
{
    int d=0;
    visited[s] = 1;
    if(visited[graph[s]]==0)    d = 1+dfs(graph[s]);
    visited[s] = 0;
    return  dist[s] = d;
}

void clr()
{
    memset(graph,0,sizeof(graph));
    memset(visited,0,sizeof(visited));
    memset(dist,-1,sizeof(dist));
}

int main()
{
    int t,cs=0,m,x,y,i;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d",&n);
        clr();
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            graph[x] = y;
        }
        ans = INT_MIN;
        pos = 0;
        for(i=1; i<=n; i++)
        {
            if(dist[i]==-1) dfs(i);
            if(ans<dist[i])
            {
                ans = dist[i];
                pos = i;
            }
        }
        printf("Case %d: %d\n",cs,pos);
    }
    return 0;
}

