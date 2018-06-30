#include<bits/stdc++.h>
using namespace std;

#define MX 250
vector<int>v[MX];
int parent[MX],visited[MX],node,edge;
queue<int>q;

bool bfs(int s)
{
    q.push(s);
    parent[s] = s;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = 1;
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                parent[v[s][i]] = parent[s]^1;
                q.push(v[s][i]);
                visited[v[s][i]] = 1;
            }
            else if(parent[s]^parent[v[s][i]]==0)   return  0;
        }
    }
    return  1;
}

int main()
{
    int i,x,y;
    while(1)
    {
        scanf("%d",&node);
        if(node==0) break;
        memset(visited,0,sizeof(visited));
        memset(parent,0,sizeof(parent));
        scanf("%d",&edge);
        for(i=0; i<=MX; i++)  v[i].clear();
        for(i=0; i<edge; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(bfs(0))    printf("BICOLORABLE.\n");
        else    printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
