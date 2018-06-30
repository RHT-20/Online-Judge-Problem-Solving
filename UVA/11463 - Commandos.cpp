#include<bits/stdc++.h>
using namespace std;

#define MX 105
vector<int>v[MX];
int visited[MX],dist[3][MX];

void bfs(int s,int k)
{
    queue<int>q;
    q.push(s);
    dist[k][s] = 0;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = 1;
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                visited[v[s][i]] = 1;
                q.push(v[s][i]);
                dist[k][v[s][i]] = dist[k][s]+1;
            }
        }
    }
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));
}

int main()
{
    int t,cs=0,n,m,i,mx,x,y;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d %d",&n,&m);
        clr();
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        scanf("%d %d",&x,&y);
        bfs(x,0);
        memset(visited,0,sizeof(visited));
        bfs(y,1);
        mx = INT_MIN;
        for(i=0; i<n; i++)  mx = max(mx,(dist[0][i]+dist[1][i]));
        printf("Case %d: %d\n",cs,mx);
    }
    return 0;
}
