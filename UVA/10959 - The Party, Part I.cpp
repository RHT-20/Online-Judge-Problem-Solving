#include<bits/stdc++.h>
using namespace std;

#define MX 1005
vector<int>v[MX];
int d[MX],visited[MX];

void bfs()
{
    int s=0;
    queue<int>q;
    d[s] = 0;
    q.push(s);
    visited[s] = 1;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                visited[v[s][i]] = 1;
                q.push(v[s][i]);
                d[v[s][i]] = d[s]+1;
            }
        }
    }
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(d,0,sizeof(d));
    memset(visited,0,sizeof(visited));
}

int main()
{
    int t,n,m,x,y,c=0,i;
    scanf("%d",&t);
    while(t--)
    {
        if(c)   puts("");
        c = 1;
        scanf("%d %d",&n,&m);
        clr();
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        bfs();
        for(i=1; i<n; i++)  printf("%d\n",d[i]);
    }
    return 0;
}
