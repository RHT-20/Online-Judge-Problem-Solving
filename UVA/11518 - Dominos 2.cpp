#include<bits/stdc++.h>
using namespace std;

#define MX 10005
vector<int>v[MX];
int visited[MX],ans;

void dfs(int s)
{
    visited[s] = 1;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0)
        {
            visited[v[s][i]] = 1;
            ans++;
            dfs(v[s][i]);
        }
    }
}

int main()
{
    int t,i,x,y,n,m,l;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0; i<MX; i++) v[i].clear();
        scanf("%d %d %d",&n,&m,&l);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
        }
        memset(visited,0,sizeof(visited));
        ans = 0;
        for(i=0; i<l; i++)
        {
            scanf("%d",&x);
            if(visited[x]==0)
            {
                ans++;
                dfs(x);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
